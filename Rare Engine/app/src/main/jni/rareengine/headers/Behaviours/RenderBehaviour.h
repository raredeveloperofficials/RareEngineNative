#pragma once
#include "Behaviour.h"
#include "GraphicsBackend.h"
namespace RareEngine{
  class RenderBehaviour:public Behaviour{
    public:
    bool visible;
    RenderBehaviour();
    virtual void Render(int program) = 0;
  };
}