//
//  myAstroid.cpp
//  asteroids
//
//  Created by Rebekah on 9/14/20.
//

#include "myAstroid.hpp"
#include "common.h"
#include "../lodepng.hpp"
#include <time.h>

//Ball constructor
myAstroid::myAstroid(){
    for (int i = 0; i < 72; i++){
        astroid_color[i] = vec3(0.0, 1.0, 0.0);
    }

    
    // Number of triangles used to draw the ball.
    int triangleAmount = 71;
    vec2 *circle = new vec2[triangleAmount+1];
    
// Drawing the ball.
    GLfloat x = 0;
    GLfloat y = 0;
      GLfloat xVal;
      GLfloat yVal;
      GLfloat radius = 0.02;
    int i;
    GLfloat twicePi = 2.0f * 3.14159265359;

    circle[0] = vec2(0,0);
    for(i = 1; i <= triangleAmount; i++) {
            xVal = x + (radius * cos(i * twicePi / (triangleAmount-1)));
            yVal = y + (radius * sin(i * twicePi / (triangleAmount-1)));
            astroid_vert[i] = vec2(xVal,yVal);
        }
    
    srand (time(NULL));
    state.astroid_velocity = normalize(vec2(0.5-rand()/(float)RAND_MAX, 0.5-rand()/(float)RAND_MAX))*0.3;//vec2(0.5, 0.5);
    state.astroid_pointing = normalize(state.astroid_velocity);
};

//Called everytime an animation tick happens
void myAstroid::update_state(){
//    std::cout<< normalize(state.astroid_velocity) << std::endl;
    state.astroid_acceleration = 0.09;
    
    // Dampening the velocity to lessen inertia.
    vec2 old_velocity = state.astroid_velocity;
    state.astroid_velocity = old_velocity * 1.03;
    
    vec2 old_position = state.astroid_cur_location;
    state.astroid_cur_location = old_position + (state.astroid_velocity * 0.03);
    
    // To keep the ball moving.
    state.modelview = Translate(state.astroid_cur_location.x, state.astroid_cur_location.y, 0.0);
    
    // Slowing the ball down.
    if (state.astroid_velocity.x > 1.0) {
        state.astroid_velocity.x -= 0.3;
    }
    if (state.astroid_velocity.x < -1.0) {
        state.astroid_velocity.x += 0.3;
    }
    // Slowing it with vel.y.
    if (state.astroid_velocity.y > 1.0) {
        state.astroid_velocity.y -= 0.3;
    }
    if (state.astroid_velocity.y < -1.0) {
        state.astroid_velocity.y += 0.3;
    }
    
    // When the ball hits the right paddle.
    // 0.92999999 is almost the paddle's x position.
    if((state.astroid_cur_location.x >= 0.92999999) and
       (state.astroid_cur_location.y <= (paddle_loc_r.y + 0.05)) and
       (state.astroid_cur_location.y >= (paddle_loc_r.y - 0.05))){
        state.astroid_velocity.x *= -2;
        player_1_score += 1;
    }
    // When the ball hits the left paddle.
    if((state.astroid_cur_location.x <= -0.92999999) and
       (state.astroid_cur_location.y <= (paddle_loc_l.y + 0.05)) and
       (state.astroid_cur_location.y >= (paddle_loc_l.y - 0.05))){
        state.astroid_velocity.x *= -2;
        player_2_score += 1;
    }
    // When the ball goes out on the right player's side.
    if(state.astroid_cur_location.x > 1.2){
        // Get graphic for this to appear.
        std::cout<< "Game Over!" << std::endl;
        std::cout<< "Player 1 score: " << player_1_score << std::endl;
        std::cout<< "Player 2 score: " << player_2_score << std::endl;
        state.game_is_over = true;
        exit(1);
    }
    // When the ball goes out on the left player's side.
    if(state.astroid_cur_location.x < -1.2){
        // Get graphic for this to appear.
        std::cout<< "Game Over!" << std::endl;
        std::cout<< "Player 1 score: " << player_1_score << std::endl;
        std::cout<< "Player 2 score: " << player_2_score << std::endl;
        state.game_is_over = true;
        exit(1);
    }
    // When the ball hits the top of the screen.
    if (state.astroid_cur_location.y > 0.9999){
        state.astroid_velocity.y *= -2;
    }
    // When the ball hits the bottom of the screen.
    if (state.astroid_cur_location.y < -0.9999){
        state.astroid_velocity.y *= -2;
    }
    // So the ball does not bounce back on screen once the game is over.
    if (state.game_is_over == true){
        state.astroid_velocity = vec2(0.0, 0.0);
    }
}

//Initialize the gl state and variables
void myAstroid::gl_init(){
  
  std::string vshader = shader_path + "vshader_Ship.glsl";
  std::string fshader = shader_path + "fshader_Ship.glsl";
  
  GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
  GLchar* fragment_shader_source = readShaderSource(fshader.c_str());

  
  GLvars.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(GLvars.vertex_shader, 1, (const GLchar**) &vertex_shader_source, NULL);
  glCompileShader(GLvars.vertex_shader);
  check_shader_compilation(vshader, GLvars.vertex_shader);
  
  GLvars.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(GLvars.fragment_shader, 1, (const GLchar**) &fragment_shader_source, NULL);
  glCompileShader(GLvars.fragment_shader);
  check_shader_compilation(fshader, GLvars.fragment_shader);
  
  GLvars.program = glCreateProgram();
  glAttachShader(GLvars.program, GLvars.vertex_shader);
  glAttachShader(GLvars.program, GLvars.fragment_shader);
  
  glLinkProgram(GLvars.program);
  check_program_link(GLvars.program);
  
  glBindFragDataLocation(GLvars.program, 0, "fragColor");
  
  GLvars.vpos_location   = glGetAttribLocation(GLvars.program, "vPos");
  GLvars.vcolor_location = glGetAttribLocation(GLvars.program, "vColor" );
  GLvars.M_location = glGetUniformLocation(GLvars.program, "M" );
  
  // Create a vertex array object
  glGenVertexArrays( 1, &GLvars.vao );
  //Set GL state to use vertex array object
  glBindVertexArray( GLvars.vao );
  
  //Generate buffer to hold our vertex data
  glGenBuffers( 1, &GLvars.buffer );
  //Set GL state to use this buffer
  glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
  
  //Create GPU buffer to hold vertices and color
  glBufferData( GL_ARRAY_BUFFER, sizeof(astroid_vert) + sizeof(astroid_color), NULL, GL_STATIC_DRAW );
  //First part of array holds vertices
  glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(astroid_vert), astroid_vert );
  //Second part of array hold colors (offset by sizeof(triangle))
  glBufferSubData( GL_ARRAY_BUFFER, sizeof(astroid_vert), sizeof(astroid_color), astroid_color );
  
  glEnableVertexAttribArray(GLvars.vpos_location);
  glEnableVertexAttribArray(GLvars.vcolor_location );
  
  glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
  glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(astroid_vert)) );
    
  glBindVertexArray(0);

}

//Draw
void myAstroid::draw(mat4 proj){
  
  glUseProgram( GLvars.program );
  glBindVertexArray( GLvars.vao );
  
  //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj * state.modelview );

  
  //Draw something
    glBindVertexArray( GLvars.vao );
    glDrawArrays(GL_TRIANGLE_FAN, 0, 71);
    glBegin(GL_LINE_LOOP);
    glEnd();

  if(!state.thruster_on){
      glClearColor(0.8,0.1,0.3,0);
      
  }else{
      glClearColor(0.0,0.0,0,0);
      
  }
    
glMatrixMode(GL_MODELVIEW);
  
  glBindVertexArray(0);
  glUseProgram(0);

}


