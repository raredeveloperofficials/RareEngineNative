#pragma once
#include "Vector4.h"
#include <map>
#include <vector>
namespace RareEngine{
  class Renderer;
  class GameObject;
    class Scene{
      private:
      Renderer* currentRenderer = nullptr;
      std::map<const char*,std::vector<GameObject*>*> objects;
      void UpdateLayer(std::vector<GameObject*>* layer,float delta,int program);
      void UpdateObject(GameObject* obj,float delta,int program);
      public:
      static const char* UI_LAYER;
      static const char* OBJECTS_LAYER;
        Vector4* const backgroundColor = new Vector4(Vector4::Dimention::COLOR_D,0,0,255,255);
        Scene();
      void SetMyRenderer(Renderer* ren);
      void AddObject(GameObject* obj,const char* layer);
      void AddObjects(const char* layer,std::vector<GameObject*> objs);
      void RemoveObject(GameObject* obj,const char* layer);
      
      GameObject* GetObjectByName(char* name,const char* layer=OBJECTS_LAYER);
      GameObject* GetObjectByTag(const char* tag,const char* layer=OBJECTS_LAYER);
      std::vector<GameObject*> GetObjectsByTag(const char* tags,const char* layer=OBJECTS_LAYER);

      Renderer* MyRenderer();

      void Update(int program);
    };
}
