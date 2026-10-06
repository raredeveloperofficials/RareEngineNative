#include "Engine.h"
#include "OpenGLBackend.h"
GraphicsBackend* RareEngine::Engine::Graphics = new RareEngine::OpenGLBackend();
namespace RareEngine {

    std::string Engine::logs;
  
  std::atomic<bool> Engine::clear(false);
}