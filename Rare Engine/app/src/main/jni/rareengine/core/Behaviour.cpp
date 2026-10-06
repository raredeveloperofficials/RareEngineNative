#include "Behaviour.h"
#include "GameObject.h"
#include "Engine.h"
namespace RareEngine{
  Behaviour::Behaviour(){
    enabled = true;
  }
  void Behaviour::OnFirstFrame(){
    RareEngine::Engine::Log("Rare Engine: Behaviour Initialized");
  }
  void Behaviour::OnEveryFrame(float delta){
    
  }
  void Behaviour::OnChildUpdatesFinish(){
    
  }
  void Behaviour::SetMyGameObject(GameObject* obj){
    MyGameObject = obj;
  }
}