#include "Renderer.h"
#include "Engine.h"
#include "GraphicsBackend.h"
#include "EngineShaders.h"
#include "Scene.h"
namespace RareEngine{
  Scene* fscene = new Scene();
Renderer::Renderer(){
  created = false;
    this->currentScene=fscene;
  this->currentScene->SetMyRenderer(this);
}
void Renderer::OnSurfaceCreated(){
    
  if(created!=true){
    Engine::Graphics->SetClearColor(0,0,1,1);
    Engine::Log("Create Program");
    created = true;
    program = Engine::Graphics->CreateProgram(toVertexShader(basicVertexRESL),toFragmentShader(basicFragmentRESL));
  }else{
    Engine::LogR("Use Program");
    Vector4* bg = currentScene->backgroundColor;
    Engine::Graphics->SetClearColor(bg->glR(),bg->glG(),bg->glB(),bg->glA());
  }
  Engine::Graphics->EnableFeature(GL_DEPTH_TEST);
    Engine::Graphics->EnableFeature(GL_CULL_FACE);
    Engine::Graphics->EnableFeature(GL_BLEND);
    Engine::Graphics->BlendFunction(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    Engine::Graphics->CullFace(GL_BACK);
    Engine::Graphics->FrontFace(GL_CCW);
}
void Renderer::OnSurfaceChanged(int width,int height){
    Engine::Graphics->SetViewport(0,0,width,height);
    this->aspect = static_cast<float>(width) / height;
    this->width = width;
    this->height = height;
}
void Renderer::OnDrawFrame(){
    
    Vector4* bg = currentScene->backgroundColor;
    if(bg->DataChanged()){
        bg->ResetDataChangedFlag();
        
        Engine::Graphics->SetClearColor(bg->glR(),bg->glG(),bg->glB(),bg->glA());
    }
    Engine::Graphics->Clear();
  if(currentScene)currentScene->Update(program);
}
int Renderer::GetScreenWidth(){
    return this->width;
}
int Renderer::GetScreenHeight(){
    return this->height;
}
float Renderer::GetAspectRatio(){
    return this->aspect;
}
void Renderer::SetCurrentScene(RareEngine::Scene* scene){
    if(scene!=nullptr){
      if(this->currentScene&&this->currentScene!=fscene)this->currentScene->SetMyRenderer(nullptr);
      if(fscene&&fscene!=scene)delete fscene;
      this->currentScene = scene;
      this->currentScene->SetMyRenderer(this);
    }
}
RareEngine::Scene* Renderer::GetCurrentScene(){
    return this->currentScene;
}
}
