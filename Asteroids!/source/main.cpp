#include "common.h"

using namespace Angel;

Ship ship = Ship(0.99, 0.93, 0.93);
Ship ship2 = Ship(-0.99, -0.93, -0.93);
myAstroid astroid;



static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
      if(action == GLFW_PRESS){
        ship.start_moving_up();
      }
      if(action == GLFW_RELEASE){
        ship.stop_moving_up();
      }
  if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
      if(action == GLFW_PRESS){
        ship.start_moving_down();
      }
      if(action == GLFW_RELEASE){
        ship.stop_moving_down();
      }
// Second paddle.
    if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
        if(action == GLFW_PRESS){
          ship2.start_moving_up();
        }
        if(action == GLFW_RELEASE){
          ship2.stop_moving_up();
        }
    if (key == GLFW_KEY_Z && (action == GLFW_PRESS || action == GLFW_REPEAT))
        if(action == GLFW_PRESS){
          ship2.start_moving_down();
        }
        if(action == GLFW_RELEASE){
          ship2.stop_moving_down();
        }
  if (key == GLFW_KEY_SPACE){
    if(action == GLFW_PRESS){
      ship.start_thruster();
    }
    if(action == GLFW_RELEASE){
      ship.stop_thruster();
    }
  }
    
}

void init(){
  
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
  glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
  ship.gl_init();
  ship2.gl_init();
  astroid.gl_init();
  
}

//Call update function 30 times a second
void animate(){
  if(glfwGetTime() > 0.033){
    glfwSetTime(0.0);
    ship.update_state();
    ship2.update_state();
    astroid.update_state();
    astroid.paddle_loc_r = ship.state.cur_location;
    astroid.paddle_loc_l = ship2.state.cur_location;
  }
}

int main(void)
{
    
  GLFWwindow* window;
  
  glfwSetErrorCallback(error_callback);
  
  if (!glfwInit())
    exit(EXIT_FAILURE);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  glfwWindowHint(GLFW_SAMPLES, 10);
  
  
  window = glfwCreateWindow(1024, 768, "Asteroids!", NULL, NULL);
  if (!window){
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  
  glfwSetKeyCallback(window, key_callback);
  
  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
  glfwSwapInterval(1);
  
  init();
  
  while (!glfwWindowShouldClose(window)){
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    
    //Pick a coordinate system that makes the most sense to you
    //(left, right, bottom, top)
    mat4 proj = Ortho2D(-1.0, 1.0,-1.0, 1.0);
    
    animate();

    
    glClear(GL_COLOR_BUFFER_BIT);
    
    ship.draw(proj);
    ship2.draw(proj);
    astroid.draw(proj);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
      
  }
      
  
  glfwDestroyWindow(window);
  
  glfwTerminate();
  exit(EXIT_SUCCESS);

    
}


