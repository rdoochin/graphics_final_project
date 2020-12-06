//
//  myAstroid.hpp
//  asteroids
//
//  Created by Rebekah on 9/14/20.
//

#ifndef myAstroid_hpp
#define myAstroid_hpp

#include <stdio.h>
#include "common.h"
//#include "common/lodepng.h"

#define _MAX_SPEED 10
#define _DAMPING 0.98
#define _ACC 3
#define _ROT 15

class myAstroid{

  vec2 astroid_vert[71];
  vec3 astroid_color[71];
  
  // Record of the ball's state.
  struct {
    vec2 astroid_cur_location;   //Current position of the center
    float angle;                 //Rotation angle
    vec2 astroid_pointing;       //Vector pointing to the front of the ball.
    
    //This function will be helpful to keep track of the direction the ball
    //is pointing.
    mat2 RotateZ2D( const GLfloat theta ){
      GLfloat angle = DegreesToRadians * theta;
      mat2 c;
      c[0][0] = c[1][1] = cos(angle);
      c[1][0] = sin(angle);
      c[0][1] = -c[1][0];
      return c;
    }
    mat4 modelview;
    vec2 astroid_velocity;
    vec2 astroid_acceleration;
    
    //Boolean if a thruster is on.
    bool thruster_on;
    bool game_is_over;
  } state;
    
  
  //OpenGL variables for the ball.
  struct {
    GLuint vao;           //Vertex array object
    GLuint program;       //shader program
    GLuint buffer;        //Vertex buffer objects
    GLuint vertex_shader, fragment_shader;  //Shaders
    GLint vpos_location, vcolor_location;   //reference to pos and color in shaders
    GLint M_location;     //Reference to matrix in shader
  } GLvars;

  
public:
  vec2 paddle_loc_r;
  vec2 paddle_loc_l;
  int player_1_score;
  int player_2_score;

  myAstroid();
  
  inline void start_thruster(){ state.thruster_on= true;}
  inline void stop_thruster() { state.thruster_on= false;}

  inline void rotateLeft() {
    state.modelview *= RotateZ(60);
  }
  inline void rotateRight(){
      state.modelview *= RotateZ(-60);
  }
    
  void update_state();
  void gl_init();
  
  void draw(mat4 proj);
  
};


#endif /* myAstroid_hpp */
