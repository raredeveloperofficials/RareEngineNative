#pragma once
#include "Behaviours/RenderBehaviour.h"
namespace RareEngine{
  class ModelRenderBehaviour:public RenderBehaviour{
    public:
    ModelRenderBehaviour();
    void Render(int program) override;
    void OnFirstFrame()override;
    void OnEveryFrame(float delta)override;
  };
}