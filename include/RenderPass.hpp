#ifndef RENDER_PASS_HPP
#define RENDER_PASS_HPP

#include <Timer.hpp>
#include <Shader.hpp>
#include <FrameBuffer.hpp>
#include <Camera.hpp>

#define AO_RESULTS_BINDING_LOCATION 3

class RenderPass
{
    protected :
        FrameBuffer FBO;
        ShaderProgram shader;
        bool isEnable = true;
        bool needClear = true;

    public : 
        RenderPass() {};

        virtual void setup() = 0;
        virtual void render(Camera &camera) = 0;
        virtual void bindResults(std::vector<ivec2> binds);
        
        FrameBuffer& getFBO();
        ShaderProgram& getShader();
        void enable();
        void disable();
        void toggle();
};

class SSAOPass : public RenderPass
{
    private :
        RenderBuffer& inputs;
        Texture2D ssaoNoiseTexture;
        std::vector<glm::vec3> ssaoKernel;
        ShaderUniform cameraProjMatrix;

    public :
        SSAOPass(RenderBuffer& inputsBuffer);
        void setup();
        void render(Camera &camera);
};

#endif