#pragma once

namespace RareEngine{
  class Scene;
    class Renderer{
        private:
        float aspect;
        int program;
        int width;
        int height;
      bool created;
        RareEngine::Scene* currentScene;
        public:
        Renderer();
        void OnSurfaceCreated();
        void OnSurfaceChanged(int width,int height);
        void OnDrawFrame();
        int GetScreenWidth();
        int GetScreenHeight();
        float GetAspectRatio();
        void SetCurrentScene(RareEngine::Scene* scene);
        RareEngine::Scene* GetCurrentScene();
    };
}
