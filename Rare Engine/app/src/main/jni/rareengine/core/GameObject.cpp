#include "GameObject.h"
#include "Scene.h"
#include "Engine.h"
#include "Behaviour.h"
#include "Behaviours/TransformBehaviour.h"
#include <algorithm>
#include <cstring>
namespace RareEngine{
  GameObject::GameObject(){
    enabled = true;
    const char* defaultName = "gameObject";
    cacheTransform = new TransformBehaviour();
    AddBehaviour(cacheTransform);
    name = new char[std::strlen(defaultName) + 1];
    std::strcpy(name, defaultName);
    RareEngine::Engine::Log("Rare Engine: GameObject created");
  }
  void GameObject::SetMyScene(Scene* scn){
    currentScene = scn;
    for(int i = 0;i<behaviours.size();i++){
      behaviours[i]->OnFirstFrame();
    }
    
    std::vector<GameObject*> chils = children;
    for(int i = 0;i<chils.size();i++){
      GameObject* chil = chils[i];
      chil->SetMyScene(currentScene);
    }
  }
  void GameObject::AddChild(GameObject* obj){
      if(this->currentScene)obj->SetMyScene(this->currentScene);
      children.push_back(obj);
  }
  void GameObject::AddChildren(std::vector<GameObject*> objs){
      for(int i = 0; i < objs.size();i++){
          AddChild(objs[i]);
      }
  }
  void GameObject::RemoveChild(GameObject* obj){
      std::vector<GameObject*>::iterator it = std::find(children.begin(),children.end(),obj);
      if(it!=children.end()){
          children.erase(it);
      }
  }
  void GameObject::AddTag(const char* tag){
    if(tag==nullptr)return;
    tags.push_back(tag);
  }
  void GameObject::RemoveTag(const char* tag){
    if(tag==nullptr)return;
    std::vector<const char*>::iterator it = std::find(tags.begin(),tags.end(),tag);
      if(it!=tags.end()){
          tags.erase(it);
      }
  }
  bool GameObject::HasTag(const char* tag){
    if(tag==nullptr)return false;
    return std::find(tags.begin(),tags.end(),tag) != tags.end();
  }
  void GameObject::SetName(char* name){
    if(name == nullptr)return;
    delete[] this->name;
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
  }
  std::string GameObject::GetName(){
    return std::string(name);
  }
  Scene* GameObject::MyScene(){
    return currentScene;
  }
  GameObject* GameObject::Parent(){
    return parent;
  }
  void GameObject::AddBehaviour(Behaviour* beh){
    if(beh==nullptr)return;
    beh->SetMyGameObject(this);
    behaviours.push_back(beh);
  }
  void GameObject::RemoveBehaviour(Behaviour* beh){
    if(beh==nullptr)return;
    std::vector<Behaviour*>::iterator it = std::find(behaviours.begin(),behaviours.end(),beh);
      if(it!=behaviours.end()){
          behaviours.erase(it);
      }
  }
  std::vector<Behaviour*> GameObject::GetAllBehaviours(){
    return behaviours;
  }
  TransformBehaviour* GameObject::GetTransformBehaviour(){
    return cacheTransform;
  }
  std::vector<GameObject*> GameObject::GetChildren(){
    return children;
  }
}