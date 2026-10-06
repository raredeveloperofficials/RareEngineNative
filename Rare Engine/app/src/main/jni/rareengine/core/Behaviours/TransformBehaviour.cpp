#include "Behaviours/TransformBehaviour.h"
#include "GameObject.h"
#include "cmath"
#include "Engine.h"
namespace RareEngine{
  TransformBehaviour::TransformBehaviour(){
    global = true;
    position = new Vector4(Vector4::Dimention::THREE_D);
    rotation = new Vector4(Vector4::Dimention::THREE_D);
    scale = new Vector4(Vector4::Dimention::THREE_D,1,1,1);
    globalposition = new Vector4(Vector4::Dimention::THREE_D);
    globalrotation = new Vector4(Vector4::Dimention::THREE_D);
    globalscale = new Vector4(Vector4::Dimention::THREE_D,1,1,1);
  }
  void TransformBehaviour::CalculateGlobals(){
    if(MyGameObject->Parent() != nullptr){
      TransformBehaviour* parent = MyGameObject->Parent()->GetTransformBehaviour();
      parent->CalculateGlobals();
      
      globalrotation->Set(*rotation + *parent->globalrotation);
      
      
      globalscale->Set(*scale + *parent->globalscale);
      
      
      globalposition->Set(
          *parent->globalposition +
          Rotate(position, parent->globalrotation)
      );
    }
  }
  Vector4 TransformBehaviour::Rotate(Vector4* pos, Vector4* rot) {
    float cx = std::cos(rot->X());
float sx = std::sin(rot->X());

float cy = std::cos(rot->Y());
float sy = std::sin(rot->Y());

float cz = std::cos(rot->Z());
float sz = std::sin(rot->Z());

// X rotation
float y1 = pos->Y() * cx - pos->Z() * sx;
float z1 = pos->Y() * sx + pos->Z() * cx;

// Y rotation
float x2 = pos->X() * cy + z1 * sy;
float z2 = -pos->X() * sy + z1 * cy;

// Z rotation
float x3 = x2 * cz - y1 * sz;
float y3 = x2 * sz + y1 * cz;

return Vector4(x3, y3, z2, pos->W());
  }
  void TransformBehaviour::OnEveryFrame(float delta){
    //RareEngine::Engine::Log("Update Trans");
  }
}