#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <App.hpp>
#include <Timer.hpp>

#include <Mesh.hpp>

class Globals
{   
    friend App;

    private :
    
        AppState _state;

        const GLFWvidmode* _videoMode;

        glm::vec2 _mousePosition;

        ivec2 _windowSize;

        std::vector<ShaderUniform> _standartShaderUniform2D;
        std::vector<ShaderUniform> _standartShaderUniform3D;

        Mesh _fullscreenQuad;

    public :

        /**
         * Globals are not cloneable.
         */
        // Globals(Globals &other) = delete;
        /**
         * Globals are note assignable.
         */
        // void operator=(const Globals&) = delete;


        const AppState state() const {return _state;};

        const GLFWvidmode* videoMode() const {return _videoMode;};

        glm::ivec2 screenResolution() const {return ivec2(_videoMode->width, _videoMode->height);};
        const int* screenResolutionAddr() const {return &(_videoMode->width);};
        const glm::vec2 mousePosition() const {return _mousePosition;};

        BenchTimer appTime;
        BenchTimer unposedTime;

        std::vector<ShaderUniform> standartShaderUniform2D() const {return _standartShaderUniform2D;};
        std::vector<ShaderUniform> standartShaderUniform3D() const {return _standartShaderUniform3D;};

        int windowWidth() const {return _windowSize.x;};
        int windowHeight() const {return _windowSize.y;};
        ivec2 windowSize() const {return _windowSize;};
        const ivec2* windowSizeAddr() const {return &_windowSize;};

        void drawFullscreenQuad() {_fullscreenQuad.drawVAO();};
};


Globals globals;

#endif