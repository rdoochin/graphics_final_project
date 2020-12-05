//
//  myAstroid.cpp
//  asteroids
//
//  Created by Rebekah on 9/14/20.
//

#include "myAstroid.hpp"
#include "common.h"
#include "../lodepng.hpp"


// //  //  //  //  //  //  // Mapping  //  //  //  //  //  //  //
GLuint buffer;
GLuint vao;
GLuint cloud_texture;
//GLuint program;
void loadFreeImageTexture(const char* lpszPathName, GLuint textureID, GLuint GLtex){
  
  std::vector<unsigned char> image;
  unsigned int width;
  unsigned int height;
  //decode
  unsigned error = lodepng::decode(image, width, height, lpszPathName, LCT_RGBA, 8);

  //if there's an error, display it
  if(error){
    std::cout << "decoder error " << error;
    std::cout << ": " << lodepng_error_text(error) << std::endl;
    return;
  }

  /* the image "shall" be in RGBA_U8 format */

  std::cout << "Image loaded: " << width << " x " << height << std::endl;
  std::cout << image.size() << " pixels.\n";
  std::cout << "Image has " << image.size()/(width*height) << "color values per pixel.\n";

  GLint GL_format = GL_RGBA;

  glActiveTexture( GLtex );
  glBindTexture( GL_TEXTURE_2D, textureID );
  glTexImage2D( GL_TEXTURE_2D, 0, GL_format, width, height, 0, GL_format, GL_UNSIGNED_BYTE, &image[0] );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
  glGenerateMipmap(GL_TEXTURE_2D);
  
  //Put things away and free memory
  image.clear();
}
//  //  //  //  //  //  //  end added mapping //    //  //  //  //  //

//Ship constructor
myAstroid::myAstroid(){
//    astroid_vert[0]= vec2(0.0, 0.0);
//    astroid_vert[1]= vec2(0.01, 0.05);
//    astroid_vert[2]= vec2(0.05, 0.0);
//    astroid_vert[3]= vec2(0.0, 0.0);
//    astroid_vert[4]= vec2(0.0, 0.0);
//    astroid_vert[5]= vec2(0.0, 0.0);
    
    astroid_color[0]= vec3(0.0, 1.0, 0.0);
    astroid_color[1]= vec3(0.0, 1.0, 0.0);
    astroid_color[2]= vec3(0.0, 1.0, 0.0);
    astroid_color[3]= vec3(0.0, 1.0, 0.0);
    astroid_color[4]= vec3(0.0, 1.0, 0.0);
    astroid_color[5]= vec3(0.0, 1.0, 0.0);
    
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
    size_t circle_bytes = (triangleAmount+1)*sizeof(vec2);
      vec3 *circle_colors = new vec3[triangleAmount+1];
      GLfloat interval = (1.0/8.0);
      GLfloat r = 0.2;
      GLfloat g = 1.0;
      GLfloat b = 0.0;
      GLfloat t = 0.0;
    for(i = 1; i < 24; i++) {
        b += b*(1-t);
        g -= g*t;
        r += 0.1;
        t = interval;
        circle_colors[i] = vec3(r, g, b);
        
        }
    // To get blue color.
    r = 1.0;
    g = 0.0;
    b = 0.2;
    t = 0.0;
    for(i = 24; i < 48 ; i++) {
        g += g*(1-t);
        r -= r*t;
        b += 0.1;
        t = interval;
        circle_colors[i] = vec3(r, g, b);
        }
    // To get green color.
    r = 0.0;
    g = 0.2;
    b = 1.0;
    t = 0.0;
    for(i = 48; i < 72 ; i++) {
        g += 0.1;
        b -= b*t;
        r += r*(1-t);
        t = interval;
        circle_colors[i] = vec3(r, g, b);
        }
    
};

//Called everytime an animation tick happens
void myAstroid::update_state(){
    std::cout<< state.astroid_cur_location  << std::endl;
    state.astroid_acceleration = 0.09;
    // might want to uncomment this, idk yet.
    //    state.astroid_pointing = vec2(1,-2);
    
    // Dampening the velocity to lessen inertia.
    vec2 old_velocity = state.astroid_velocity;
    state.astroid_velocity = old_velocity + (state.astroid_acceleration * 0.03);
    
    vec2 old_position = state.astroid_cur_location;
    state.astroid_cur_location = old_position + (state.astroid_velocity * 0.03);
    
    // this doesnt work to decrease the speed of the ball
//    vec2 old_acceleration = state.astroid_acceleration;
//    state.astroid_acceleration = old_acceleration * 0.03;
    
    // To keep the ball moving.
    state.modelview = Translate(state.astroid_cur_location.x, state.astroid_cur_location.y, 0.0);
    
    // not working to slow the ball down.
    if (state.astroid_velocity.x > 2.0) {
        state.astroid_velocity.x -= 0.3;
    }
    if (state.astroid_velocity.x < -2.0) {
        state.astroid_velocity.x += 0.3;
    }
    if (state.astroid_cur_location.x > 2.0) {
        state.astroid_cur_location.x -= 0.3;
    }
    if (state.astroid_cur_location.x < -2.0) {
        state.astroid_cur_location.x += 0.3;
    }
    
    // When the ball hits the right paddle.
    // 0.92999999 is almost the paddle's x position.
    if((state.astroid_cur_location.x >= 0.92999999) and
       (state.astroid_cur_location.y <= (paddle_loc_r.y + 0.05)) and
       (state.astroid_cur_location.y >= (paddle_loc_r.y - 0.05))){
        state.astroid_velocity.x *= -2;
//        std::cout<< state.astroid_cur_location.y  << std::endl;
    }
    // When the ball hits the left paddle.
    // 0.92999999 is almost the paddle's x position.
    if((state.astroid_cur_location.x <= -0.92999999) and
       (state.astroid_cur_location.y <= (paddle_loc_l.y + 0.05)) and
       (state.astroid_cur_location.y >= (paddle_loc_l.y - 0.05))){
        state.astroid_velocity.x *= -2;
    }
    // When the ball goes out on the right player's side.
    if(state.astroid_cur_location.x > 0.93){
        // Get graphic for this to appear.
        std::cout<< "Game Over!" << std::endl;
    }
    // When the ball goes out on the left player's side.
    if(state.astroid_cur_location.x < -0.93){
        // Get graphic for this to appear.
        std::cout<< "Game Over!" << std::endl;
    }
    // When the ball hits the top of the screen.
    if (state.astroid_cur_location.y > 0.9999){
        state.astroid_velocity.y *= -2;
    }
    // When the ball hits the bottom of the screen.
    if (state.astroid_cur_location.y < -0.9999){
        state.astroid_velocity.y *= -2;
    }
    
    if(!state.thruster_on){
        state.astroid_acceleration = state.astroid_pointing;
    }
    else{
        state.astroid_acceleration = 0;
        state.astroid_velocity = state.astroid_velocity * 0.98;
    }
    
//    // Phong Shading.
//    color4 material_ambient( ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), 1.0 );
//    color4 material_diffuse( ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), 1.0 );
//    color4 material_specular( ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), 1.0 );
//
//    //mess with this later
//    float material_shininess = rand() % 11;
}

//Initialize the gl state and variables
void myAstroid::gl_init(){
  
  std::string vshader = shader_path + "vshader_Ship.glsl";
  std::string fshader = shader_path + "fshader_Ship.glsl";
  
  GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
  GLchar* fragment_shader_source = readShaderSource(fshader.c_str());
    
    // Added.
//    glGenTextures( 1, &cloud_texture );
  
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
    
//  //  //  //  //  // Mapping //  //  //  //  //  //
    //===== Send data to GPU ======
//    glGenVertexArrays( 1, &vao );
//    glGenBuffers( 1, &buffer);
//
//    mesh = new Mesh();
//    mesh->makeSphere(32);
//
//    glGenTextures( 1, &cloud_texture );
//
//    std::string cloud_img = "../images/cloud_combined.png";
//    loadFreeImageTexture(cloud_img.c_str(), cloud_texture, GL_TEXTURE1);
//
//    glBindVertexArray( vao );
//    glBindBuffer( GL_ARRAY_BUFFER, buffer );
//    /* fill to size of vertices */{
//      std::size_t vertices_size = mesh->vertices.size();
//      std::size_t uvs_size = mesh->uvs.size();
//      std::size_t normals_size = mesh->normals.size();
//      if (uvs_size < vertices_size) {
//        mesh->uvs.resize(vertices_size);
//        for (std::size_t j = uvs_size; j < vertices_size; ++j) {
//          mesh->uvs[j] = vec2(0.f,0.f);
//        }
//      }
//      if (normals_size < vertices_size) {
//        mesh->normals.resize(vertices_size);
//        for (std::size_t j = normals_size; j < vertices_size; ++j) {
//          mesh->normals[j] = vec3(1.f,1.f,1.f);
//        }
//      }
//    }
//
//
//    unsigned int vertices_bytes = mesh->vertices.size()*sizeof(vec4);
//    unsigned int normals_bytes  = mesh->normals.size()*sizeof(vec3);
//    unsigned int uv_bytes =  mesh->uvs.size()*sizeof(vec2);
//
//    glBufferData( GL_ARRAY_BUFFER, vertices_bytes + normals_bytes+uv_bytes, NULL, GL_STATIC_DRAW );
//    unsigned int offset = 0;
//    if (vertices_bytes > 0)
//      glBufferSubData( GL_ARRAY_BUFFER, offset, vertices_bytes, &mesh->vertices[0] );
//    offset += vertices_bytes;
//    if (normals_bytes > 0)
//      glBufferSubData( GL_ARRAY_BUFFER, offset, normals_bytes,  &mesh->normals[0] );
//    offset += normals_bytes;
//    if (uv_bytes > 0)
//      glBufferSubData( GL_ARRAY_BUFFER, offset, uv_bytes,  &mesh->uvs[0] );
//
//    glEnableVertexAttribArray( vNormal );
//    glEnableVertexAttribArray( vPosition );
//    glEnableVertexAttribArray( vTexCoord );
//
//
//    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
//    glVertexAttribPointer( vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertices_bytes) );
//    glVertexAttribPointer( vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertices_bytes+normals_bytes) );

    //===== End: Send data to GPU ======
    
//    glUniform1i( glGetUniformLocation(program, "textureCloud"), 1 );
//  //  //  //  //  //  //  //  //  //  //  //
    
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


