#include "OpenGLBackend.h"

#include <GLES3/gl3.h>
#include <string>
#include "Engine.h"
namespace RareEngine
{
    void OpenGLBackend::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    }
    void OpenGLBackend::BlendFunction(int sfact,int dfact) {
      glBlendFunc(sfact,dfact);
    }
    void OpenGLBackend::CullFace(int type) {
      glCullFace(type);
    }
    void OpenGLBackend::FrontFace(int face) {
      glFrontFace(face);
    }
    void OpenGLBackend::SetClearColor(
        float r,
        float g,
        float b,
        float a
    )
    {
        glClearColor(r, g, b, a);
    }

    void OpenGLBackend::SetViewport(
        int x,
        int y,
        int width,
        int height
    )
    {
        glViewport(x, y, width, height);
    }
    void OpenGLBackend::UseProgram(int program){
        glUseProgram(program);
    }
    void OpenGLBackend::EnableFeature(int feature) {
        glEnable(feature);
    }
    void OpenGLBackend::DisableFeature(int feature) {
        glEnable(feature);
    }
    int OpenGLBackend::CreateProgram(const std::string& vertex,const std::string& fragment){
  
        int vertshad = glCreateShader(GL_VERTEX_SHADER);
        int fragshad = glCreateShader(GL_FRAGMENT_SHADER);
        const char* vsource = vertex.c_str();
        const char* fsource = fragment.c_str();
        //RareEngine::Engine::LogE(vsource);
        glShaderSource(vertshad,1,&vsource,nullptr);
        glShaderSource(fragshad,1,&fsource,nullptr);
        //RareEngine::Engine::LogR("Before compile");
        glCompileShader(vertshad);
        glCompileShader(fragshad);
      //RareEngine::Engine::LogR("After compile");
      bool pgmerr = false;
      GLint vertcomp;
      GLint fragcomp;
      glGetShaderiv(vertshad,GL_COMPILE_STATUS,&vertcomp);
      glGetShaderiv(fragshad,GL_COMPILE_STATUS,&fragcomp);
      //RareEngine::Engine::LogR("compile,status");
      if(vertcomp==GL_FALSE){
        pgmerr = true;
        GLint loglen;
        glGetShaderiv(vertshad,GL_INFO_LOG_LENGTH,&loglen);
        //RareEngine::Engine::LogR("Log len");
        if(loglen>0){
        
          GLchar* log = new GLchar[loglen+1];
          //RareEngine::Engine::LogR("String created");
        
        glGetShaderInfoLog(vertshad,loglen,nullptr,log);
         // RareEngine::Engine::LogR("Got log");
          log[loglen] = '\0';
          char* lg = reinterpret_cast<char*>(log);
        RareEngine::Engine::LogE("Vertex Shader: Error"+ std::string(lg)+ "\n\n");
          delete[] log;
        }
        //RareEngine::Engine::LogR("After");

      }
      if(fragcomp==GL_FALSE){
        pgmerr = true;
        GLint loglen;
        glGetShaderiv(fragshad,GL_INFO_LOG_LENGTH,&loglen);
        //RareEngine::Engine::LogR("Log len2");
        if(loglen>0){
        GLchar* log = new GLchar[loglen+1];
        glGetShaderInfoLog(fragshad,loglen,nullptr,log);
          log[loglen] = '\0';
          char* lg = reinterpret_cast<char*>(log);
        RareEngine::Engine::LogE("Fragment Shader: Error"+ std::string(log)+ "\n\n");
          delete[] log;
        }
      }
      int pgm = glCreateProgram();
      //RareEngine::Engine::LogR("program created");
    
        glAttachShader(pgm,vertshad);
        glAttachShader(pgm,fragshad);
       // RareEngine::Engine::LogR("shader attached");
        glLinkProgram(pgm);
     // RareEngine::Engine::LogR("Program linked");
      GLint linked;
      glGetProgramiv(pgm,GL_LINK_STATUS,&linked);
      //RareEngine::Engine::LogR("Link Status");
      if(linked==GL_FALSE){
        pgmerr = true;
        GLint loglen;
        glGetProgramiv(pgm,GL_INFO_LOG_LENGTH,&loglen);
        
        if(loglen>0){
        GLchar* log = new GLchar[loglen+1];
          //RareEngine::Engine::LogR("String created");

        glGetProgramInfoLog(pgm,loglen,nullptr,log);
         // RareEngine::Engine::LogR("got log");
          log[loglen] = '\0';
          char* lg = reinterpret_cast<char*>(log);
        RareEngine::Engine::LogE("Program link: Error"+std::string(lg)+"\n\n");
          delete[] log;
        }
      }
      
      if(pgmerr){
        RareEngine::Engine::LogW("Something is wrong in program");
      }else
      RareEngine::Engine::LogR("Program Sucessfully Created");
        glDeleteShader(vertshad);
        glDeleteShader(fragshad);
        if(!pgmerr)
        return pgm;
      else{
        glDeleteProgram(pgm);
        return -1;
      }
    }
}
