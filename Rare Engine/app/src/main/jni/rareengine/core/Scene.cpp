#include "Scene.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Engine.h"
#include "Behaviour.h"
#include <string>
#include <algorithm>
namespace RareEngine{
const char* Scene::UI_LAYER = "UI";
const char* Scene::OBJECTS_LAYER = "OBJECTS";
Scene::Scene(){
    objects[UI_LAYER] = new std::vector<GameObject*>();
    objects[OBJECTS_LAYER] = new std::vector<GameObject*>();
}
void Scene::SetMyRenderer(Renderer* ren){
  currentRenderer = ren;
}
void Scene::AddObject(GameObject* obj,const char* layer){
  obj->SetMyScene(this);
  if(objects.find(layer)==objects.end()){
    objects[layer] = new std::vector<GameObject*>();
  }
  objects[layer]->push_back(obj);
}

void Scene::AddObjects(const char* layer,std::vector<GameObject*> objs){
  for(int i = 0; i < objs.size();i++){
    AddObject(objs[i],layer);
  }
}
void Scene::RemoveObject(GameObject* obj,const char* layer){
  std::vector<GameObject*>& inventory =*objects[layer];
  std::vector<GameObject*>::iterator it =
    std::find(inventory.begin(), inventory.end(), obj);

if (it != inventory.end())
    inventory.erase(it);
}
  GameObject* Scene::GetObjectByName(char* name,const char* layer){
    std::vector<GameObject*> objlay =*objects[layer];
    for(int i = 0; i < objlay.size();i++){
      GameObject* obj = objlay[i];
      if(obj->GetName()==name){
        return obj;
      }
    }
    return nullptr;
  }
  GameObject* Scene::GetObjectByTag(const char* tag,const char* layer){
    std::vector<GameObject*> objlay =*objects[layer];
    for(int i = 0; i < objlay.size();i++){
      GameObject* obj = objlay[i];
      if(obj->HasTag(tag)){
        return obj;
      }
    }
    return nullptr;
  }
  std::vector<GameObject*> Scene::GetObjectsByTag(const char* tag,const char* layer){
    std::vector<GameObject*> objlay =*objects[layer];
    std::vector<GameObject*> objswn;
    for(int i = 0; i < objlay.size();i++){
      GameObject* obj = objlay[i];
      if(obj->HasTag(tag)){
        objswn.push_back(obj);
      }
    }
    return objswn;
  }
  Renderer* Scene::MyRenderer(){
    return currentRenderer;
  }
  void Scene::Update(int program){
    UpdateLayer(objects[OBJECTS_LAYER],0,program);
    for (auto& pair : objects) {
    if (pair.first != OBJECTS_LAYER &&
        pair.first != UI_LAYER) {
        UpdateLayer(pair.second,0,program);
    }
    }
    UpdateLayer(objects[UI_LAYER],0,program);
  }
  void Scene::UpdateLayer(std::vector<GameObject*>* layer,float delta,int program){
    for(int i = 0;i<layer->size();i++){
      GameObject* obj = (*layer)[i];
      UpdateObject(obj,delta,program);
    }
  }
  void Scene::UpdateObject(GameObject* obj,float delta,int program){
    std::vector<Behaviour*> beh = obj->GetAllBehaviours();
      for(int i = 0;i<beh.size();i++){
        beh[i]->OnEveryFrame(delta);
        //RareEngine::Engine::Log("Update Every Frame"+beh.size());
      }
    std::vector<GameObject*> childs = obj->GetChildren();
    for(int i = 0;i<childs.size();i++){
        UpdateObject(childs[i],delta,program);
    }
    for(int i = 0;i<beh.size();i++){
        beh[i]->OnChildUpdatesFinish();
    }
  }
}
