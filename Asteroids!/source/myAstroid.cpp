//
//  myAstroid.cpp
//  asteroids
//
//  Created by Rebekah on 9/14/20.
//

#include "myAstroid.hpp"

#include "common.h"

//Ship constructor
myAstroid::myAstroid(){
    
    GLfloat red = 0.0f;

    state.astroid_pointing = vec2(0,1);
  //Set up initial state here
    astroid_vert[0] = vec2(-0.65,  0.25);
    astroid_vert[1] = vec2(-0.6,  0.2);
    astroid_vert[2] = vec2(-0.7,  0.1);
    astroid_vert[3] = vec2(-0.8,  0.2);
    astroid_vert[4] = vec2(-0.7,  0.4);
    astroid_vert[5] = vec2(-0.65,  0.5);
    astroid_vert[6] = vec2(-0.6,  0.35);

    size_t astroid_vert_bytes = 6*sizeof(vec2);
    
    astroid_color[0] = vec3( 1.0, 0.0, 0.0);
    astroid_color[1] = vec3( 1.0, 0.0, 0.0);
    astroid_color[2] = vec3( 0.0, 0.0, 1.0);
    astroid_color[3] = vec3( 0.0, 0.0, 1.0);
    astroid_color[4] = vec3( 0.0, 1.0, 0.0);
    astroid_color[5] = vec3( 0.0, 1.0, 0.0);
    astroid_color[6] = vec3( 1.0, 1.0, 1.0);
    size_t astroid_color_bytes = 6*sizeof(vec3);
};

//Called everytime an animation tick happens
void myAstroid::update_state(){
    state.astroid_acceleration = 0.01;
    state.astroid_pointing = vec2(1,0);
  // Things to do:
  //a = F
  //Force is in the direction the ship is pointing
  //Clamp acceleration at some maximum value

  vec2 old_velocity = state.astroid_velocity;
  //v  = old_velocity + a*dt
    
  state.astroid_velocity = old_velocity + (state.astroid_acceleration * 0.03);
    //state.astroid_velocity = 0.5;
  // clamp velocity at a maximum value
  // Dampen the velocity at every timestep to lessen intertia
  //p  = old_position + v*dt
    
    vec2 old_position = state.astroid_cur_location;
    
    // come back to if fucked up
    state.astroid_cur_location = old_position + (state.astroid_velocity * 0.03);
  // Wrap the ship position when at the boundary
    if(state.astroid_cur_location.x >= 1){
        state.astroid_cur_location.x = -1;
    }
    // When the ship is not yet at the top of the screen.
    state.modelview = Translate(state.astroid_cur_location.x, state.astroid_cur_location.y, 0.0);
    
    if(!state.thruster_on){
        state.astroid_acceleration = state.astroid_pointing;
        state.modelview *= RotateZ(-10);
    }
    else{
        state.astroid_acceleration = 0;
        state.astroid_velocity = state.astroid_velocity * 0.98;
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
    glDrawArrays(GL_LINE_LOOP, 0, 7);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 7; i++){
        astroid_color[i] = (vec3(0.0, 1.0, 1.0));
    }
    glEnd();

  if(state.thruster_on){
    //Maybe draw something different if the thruster is on
      //state.modelview *= RotateZ(-10);
      //state.modelview *= glColor3f(0,0,0);
      glClearColor(1.0,0.0,0,0);
    
      //size_t ship_color_bytes = 3*sizeof(vec3);
      //this->red = 1.0f;
      //state.modelview *= RotateZ(-10);
      
      //size_t ship_vert_bytes = 6*sizeof(vec2);
      //astroid_vert[3] = vec2(0.0,  -0.025);
      //astroid_vert[4] = vec2(0.02,  -0.025);
      //ship_vert[5] = vec2(0.0,  0.0);
      
      //astroid_color[3] = vec3( 1.0, 0.0, 1.0);
      //astroid_color[4] = vec3( 1.0, 0.0, 1.0);
      //ship_color[5] = vec3( 0.0, 1.0, 1.0);
      //size_t ship_color_bytes = 6*sizeof(vec3);
      
  }else{
      glClearColor(0.0,0.0,0,0);
      
//=======
//>>>>>>> Stashed changes
  }
    
glMatrixMode(GL_MODELVIEW);
  
  glBindVertexArray(0);
  glUseProgram(0);

}

