//
//  Ship.h
//  Asteroids
//
//  Created by Brian Summa on 6/5/15.
//
//

#ifndef __Asteroids__Ship__
#define __Asteroids__Ship__

#include "common.h"

#define _MAX_SPEED 10
#define _DAMPING 0.98
#define _ACC 3
#define _ROT 15

class Bullet_System;
class Ship{

  //Placeholders so everything compiles.  Customize for your ship
  vec2 ship_vert[5];
  vec3 ship_color[5];
  
  //Record of the ship's state
public:
  struct {
      Bullet_System*ship_system;
    vec2 cur_location;   //Current position of the center
    float angle;         //Rotation angle
    vec2 pointing;       //Vector pointing to the front of the ship
    
    //This function will be helpful to keep track of the direction the ship
    //is pointing
    mat2 RotateZ2D( const GLfloat theta ){
      GLfloat angle = DegreesToRadians * theta;
      mat2 c;
      c[0][0] = c[1][1] = cos(angle);
      c[1][0] = sin(angle);
      c[0][1] = -c[1][0];
      return c;
    }
    mat4 modelview;
    vec2 velocity;       //Velocity
    vec2 acceleration;
    vec2 time;
      
    bool thruster_on;    //Boolean if a thruster is on
  } state;
  
  //OpenGL variables for a ship
  struct {
    GLuint vao;           //Vertex array object
    GLuint program;       //shader program
    GLuint buffer;        //Vertex buffer objects
    GLuint vertex_shader, fragment_shader;  //Shaders
    GLint vpos_location, vcolor_location;   //reference to pos and color in shaders
    GLint M_location;     //Reference to matrix in shader
  } GLvars;

  
public:
  

  Ship();
    void pew_pew();
  inline void start_thruster(){ state.thruster_on= true;}
  inline void stop_thruster() { state.thruster_on= false;}

  inline void rotateLeft() {
    //Do something
    state.modelview *= RotateZ(60);
  }
  inline void rotateRight(){
    //Do something
      state.modelview *= RotateZ(-60);
  }
    
  void update_state();
  
  void gl_init();  
  
  void draw(mat4 proj);
  

};

#endif /* defined(__Asteroids__Ship__) */
