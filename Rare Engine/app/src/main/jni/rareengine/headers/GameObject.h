#pragma once 
#include <vector>
#include<string>
namespace RareEngine{
  class Scene;
  class Behaviour;
  class TransformBehaviour;
  class GameObject{
    private:
    char* name;
    std::vector<const char*> tags;
    GameObject* parent = nullptr;
    Scene* currentScene = nullptr;
    TransformBehaviour* cacheTransform;
    std::vector<GameObject*> children;
    std::vector<Behaviour*> behaviours;
    public:
    bool enabled;
    GameObject();
    void SetMyScene(Scene* scn);
    void AddChild(GameObject* obj);
    void AddChildren(std::vector<GameObject*> obj);
    void RemoveChild(GameObject* obj);
    
    void AddTag(const char* tag);
    void RemoveTag(const char* tag);
    bool HasTag(const char* tag);
    void SetName(char* name);
    std::string GetName();
    Scene* MyScene();
    GameObject* Parent();
    std::vector<GameObject*> GetChildren();

    void AddBehaviour(Behaviour* beh);
    void RemoveBehaviour(Behaviour* beh);
    std::vector<Behaviour*> GetAllBehaviours();

    TransformBehaviour* GetTransformBehaviour();
    
  };
}