#pragma once
namespace RareEngine{
  class GameObject;
  class Behaviour{
    protected:
    GameObject* MyGameObject;
    public:
    bool enabled;
    Behaviour();
    virtual void OnFirstFrame();
    virtual void OnEveryFrame(float delta);
    virtual void OnChildUpdatesFinish();
    void SetMyGameObject(GameObject* obj);
  };
}