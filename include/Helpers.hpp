#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <ObjectGroup.hpp>

class PointLightHelperMODEL : public MeshModel3D
{
    private : 

        const ScenePointLight light;

    public :

        PointLightHelperMODEL(ScenePointLight light);
        // void update(bool forceUpdate = false) override;
        // void drawVAO(GLenum mode = GL_TRIANGLES);
        // void draw(GLenum mode = GL_TRIANGLES);

        void preDrawRoutine() override;
};

class PointLightHelper : public ObjectGroup
{
    private : 

        const ScenePointLight light;

    public :

        PointLightHelper(ScenePointLight light);
        void update(bool forceUpdate = false) override;
        // void drawVAO(GLenum mode = GL_TRIANGLES);
        // void draw(GLenum mode = GL_TRIANGLES);

        // void preDrawRoutine() override;
};


#endif