#pragma once


#include "GraphicsBackend.h"

namespace RareEngine
{
    class OpenGLBackend : public GraphicsBackend
    {
    public:
        void Clear() override;

        void SetClearColor(
            float r,
            float g,
            float b,
            float a
        ) override;

        void SetViewport(
            int x,
            int y,
            int width,
            int height
        ) override;
        void UseProgram(int program) override;
        void EnableFeature(int feature) override;
        void DisableFeature(int feature) override;
        int CreateProgram(const std::string& vertex,const std::string& fragment) override;
        void BlendFunction(int sfact,int dfact) override;
        void CullFace(int type) override;
        void FrontFace(int face) override;
    };
}
