#pragma once
#include "Behaviour.h"
#include "Vector4.h"
namespace RareEngine{
  class TransformBehaviour:public Behaviour{
    private:
    Vector4 Rotate(Vector4* pos,Vector4* rot);//TransformBehaviour function that CalculateGlobals needs
    public:
    bool global;
    TransformBehaviour();
    Vector4 *position,*rotation,*scale,*globalposition,*globalrotation,*globalscale;
    void CalculateGlobals();
    void OnEveryFrame(float delta) override;
  };
}