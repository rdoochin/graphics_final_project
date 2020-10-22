//
//  Ship.cpp
//  Asteroids
//
//  Created by Brian Summa on 6/5/15.
//
//

#include "common.h"


// Bullet Class

class Bullet{
public:
  Bullet(Ship* ship){    //passing in reference to a later ship
    //Code changes here
    loc = ship->state.cur_location;
    color = vec3(rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX);
    accel = vec2(0.0, 9.8);
      vel =   normalize(vec2(0.5-rand()/(float)RAND_MAX, 0.5-rand()/(float)RAND_MAX))*3.0;
  };
  vec2 loc;
  vec2 vel;
  vec2 accel;
  vec3 color;
};


class Bullet_System{
public:
  
  Bullet_System(Ship*ship){
      this->ship = ship;
  };
  ~Bullet_System(){
    for(unsigned int i=0; i < bullets.size(); i++)
      delete bullets[i];
    bullets.clear();
  }
  
  GLuint vao;
  GLuint program;
  GLuint buffer;
  GLuint vertex_shader, fragment_shader;
  GLint vpos_location, vcolor_location;
  GLint PM_location;

  std::vector < Bullet * > bullets;
    Ship*ship;
  
  void init(){
    std::string vshader = shader_path + "vshader_Ship.glsl";
    std::string fshader = shader_path + "fshader_Ship.glsl";
    
    GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
    GLchar* fragment_shader_source = readShaderSource(fshader.c_str());
    
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, (const GLchar**) &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    check_shader_compilation(vshader, vertex_shader);
    
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, (const GLchar**) &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    check_shader_compilation(fshader, fragment_shader);
    
    program = glCreateProgram();            // CHECK THIS LINE LATER
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    
    glLinkProgram(program);
    check_program_link(program);
    
    glBindFragDataLocation(program, 0, "fragColor");
    
    vpos_location   = glGetAttribLocation(program, "vPos");
    vcolor_location = glGetAttribLocation( program, "vColor" );
    PM_location = glGetUniformLocation( program, "ProjectionModelview" ); //GLvars.program, "M" in ship init()

    // Create a vertex array object
    glGenVertexArrays( 1, &vao );
    //Set GL state to use vertex array object
    glBindVertexArray( vao );
    
    //Generate buffer to hold our vertex data
    glGenBuffers( 1, &buffer );
    
    glEnableVertexAttribArray(vpos_location);
    glEnableVertexAttribArray( vcolor_location );
    
    glBindVertexArray(0);
    
  };
  
  void update(){
  
    vec2 *pos = new vec2[bullets.size()];
    vec3 *col = new vec3[bullets.size()];

    for(unsigned int i=0; i < bullets.size(); i++){
      pos[i] = bullets[i]->loc;
      col[i] = bullets[i]->color;
    }
    
    //Set GL state to use this buffer
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    
    //Create GPU buffer to hold vertices and color
    glBufferData( GL_ARRAY_BUFFER, bullets.size()*sizeof(vec2) + bullets.size() *sizeof(vec3), NULL, GL_STATIC_DRAW );
    //First part of array holds vertices
    glBufferSubData( GL_ARRAY_BUFFER, 0, bullets.size()*sizeof(vec2), pos );
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData( GL_ARRAY_BUFFER, bullets.size()*sizeof(vec2), bullets.size()*sizeof(vec3), col );

    glVertexAttribPointer( vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    glVertexAttribPointer( vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(bullets.size()*sizeof(vec2)) );

    glBindBuffer( GL_ARRAY_BUFFER, 0 );

    delete[] pos;
    delete[] col;

  };
  
  void emit(){
    bullets.push_back(new Bullet(ship));
  };
  
  void step(float dt){
    //Code changes here
    for (std::vector< Bullet * >::iterator it = bullets.begin() ; it != bullets.end(); ++it){
      (*it)->vel += (*it)->accel*dt;
      (*it)->loc += (*it)->vel*dt;
        
        if((*it)->loc.y < -5 || (*it)->loc.y > 5){
            (*it)->vel.y *= -0.5;
        }
        if ((*it)->loc.x < -5 || (*it)->loc.x > 5){
            (*it)->vel.x *= -0.5;
            //std::cout<<(*it)->vel.y << std::endl;
        }
        if((*it)->vel.y < 0.001 && (*it)->vel.y > -0.001){
            //particles.clear();
            delete *it; // refering to the particle
            it= bullets.erase(it); // erasing the iterator from the particles list
            
            std::cout<< "it dead" << std::endl;
        }
        
    }
  };
};

static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void animate(Bullet_System *bullets){
  //Do 30 times per second
  if(glfwGetTime() > (1.0/60.0)){
    bullets->step((1.0/60.0));
    bullets->emit();
    glfwSetTime(0.0);
  }
}
//Ship constructor
Ship::Ship(){
    state.ship_system = new Bullet_System(this);
    GLfloat red = 0.0f;

    state.pointing = vec2(0,1);
  //Set up initial state here
    ship_vert[0] = vec2(0.0,  0.05);
    ship_vert[1] = vec2(0.04330127,  -0.025);
    ship_vert[2] = vec2(-0.04330127,  -0.025);
    size_t ship_vert_bytes = 6*sizeof(vec2);
    
    ship_color[0] = vec3( 0.0, 0.0, 1.0);
    ship_color[1] = vec3( 0.0, 0.0, 1.0);
    ship_color[2] = vec3( 0.0, 0.0, 1.0);
    size_t ship_color_bytes = 6*sizeof(vec3);
};

//Called everytime an animation tick happens
void Ship::update_state(){  //call bullet_s update state from here.
    state.ship_system -> update();

    pew_pew();
    
  // Things to do:
  //a = F
  //Force is in the direction the ship is pointing
  //Clamp acceleration at some maximum value
    vec2 old_velocity = state.velocity;
    state.velocity = old_velocity + (state.acceleration * 0.03);
    
  // clamp velocity at a maximum value
  // Dampen the velocity at every timestep to lessen intertia
    vec2 old_position = state.cur_location;

    state.cur_location = old_position + (state.velocity * 0.03);
  // Wrap the ship position when at the boundary
    if(state.cur_location.y >= 1){
        state.cur_location.y = -1;
    }
    // When the ship is not yet at the top of the screen.
    state.modelview = Translate(state.cur_location.x, state.cur_location.y, 0.0);
    
    // When the thruster is on.
    if(state.thruster_on){
        state.acceleration = state.pointing;
        
    }
    else{
        state.acceleration = 0;
        state.velocity = state.velocity * 0.98;
    }
    
}
// For firing bullets.
void Ship::pew_pew(){
    state.ship_system -> emit();
}

//Initialize the gl state and variables
void Ship::gl_init(){
  //Ship

    state.ship_system -> init();
    
  
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
  glBufferData( GL_ARRAY_BUFFER, sizeof(ship_vert) + sizeof(ship_color), NULL, GL_STATIC_DRAW );
  //First part of array holds vertices
  glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ship_vert), ship_vert );
  //Second part of array hold colors (offset by sizeof(triangle))
  glBufferSubData( GL_ARRAY_BUFFER, sizeof(ship_vert), sizeof(ship_color), ship_color );
  
  glEnableVertexAttribArray(GLvars.vpos_location);
  glEnableVertexAttribArray(GLvars.vcolor_location );
  
  glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
  glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(ship_vert)) );
  
  glBindVertexArray(0);

}

//Draw a ship
void Ship::draw(mat4 proj){
    
  glUseProgram( GLvars.program );
  glBindVertexArray( GLvars.vao );
  
  //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj * state.modelview );

  
  //Draw something
    glBindVertexArray( GLvars.vao );
    glDrawArrays(GL_TRIANGLES, 0, 4);
    
// new from Bullet_System.
    glUseProgram(state.ship_system->program);
    glBindVertexArray( state.ship_system->vao );
    state.ship_system->update();
    glUniformMatrix4fv( state.ship_system->PM_location, 1, GL_TRUE, proj* state.modelview );
    glDrawArrays(GL_POINTS, 0, state.ship_system->bullets.size());
    
    //std::cout<< state.ship_system->bullets.size() << std::endl;
  if(state.thruster_on){
    // Draw something different if the thruster is on.
      state.modelview *= RotateZ(-10);
      glClearColor(1.0,0.0,0,0);
    
      ship_vert[3] = vec2(0.0,  -0.025);
      ship_vert[4] = vec2(0.02,  -0.025);
      ship_color[3] = vec3( 1.0, 0.0, 1.0);
      ship_color[4] = vec3( 1.0, 0.0, 1.0);

      
  }else{
      glClearColor(0.0,0.0,0,0);
      
  }
    
    

}
/*
 
 The three Boolean expressions check if the end points of the ship are within the boundaries of the asteroid with the exception of the third which prevents a collision in the event of the ship being in the concave region.
 
bool Ship::coll(myAstroid*astroid){
    if(
       
       (ship_vert[0].y <= astroid.astroid_vert[5].y and ship_vert[0].y >= astroid.astroid_vert[2].y ) and
         (ship_vert[0].x <= astroid.astroid_vert[6].x and ship_vert[0].x >= astroid.astroid_vert[3].x) and
            !(ship_vert[0].x <= astroid.astroid_vert[2].x) or
       
       (ship_vert[1].y <= astroid.astroid_vert[5].y and ship_vert[1].y >= astroid.astroid_vert[2].y ) and
       (ship_vert[1].x <= astroid.astroid_vert[6].x and ship_vert[1].x >= astroid.astroid_vert[3].x) and
          !(ship_vert[1].x <= astroid.astroid_vert[2].x) or
       
       (ship_vert[2].y <= astroid.astroid_vert[5].y and ship_vert[2].y >= astroid.astroid_vert[2].y ) and
       (ship_vert[2].x <= astroid.astroid_vert[6].x and ship_vert[2].x >= astroid.astroid_vert[3].x) and
          !(ship_vert[2].x <= astroid.astroid_vert[2].x)
    
       ){
        std::cout<< "Game over" << std::endl;
        return true;
    }
}
*/


