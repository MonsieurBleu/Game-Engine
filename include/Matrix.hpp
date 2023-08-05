#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <string.h>
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace glm;

class ModelState3D
{
    private :
        bool needUpdate = true;

    public :
        vec3 position      = vec3(0.f);
        vec3 scale         = vec3(1.f);
        vec3 rotation      = vec3(0.f);
        float depth        = 0.f;
        mat4 rotationMatrix = mat4(1.0);
        mat4 modelMatrix = mat4(1.0);

    ModelState3D& scaleScalar(float newScale)
    {
        scale = vec3(newScale);
        needUpdate = true;
        return *this;
    }

    ModelState3D& setPosition(vec3 newPosition)
    {
        position = newPosition;
        needUpdate = true;
        return *this;
    }

    ModelState3D& setRotation(vec3 newRotation)
    {   
        rotation = newRotation;

        // rotationMatrix = rotate(mat4(1.0), rotation.x, vec3(1.0, 0.0, 0.0));
        // rotationMatrix = rotate(rotationMatrix, rotation.y, vec3(0.0, 1.0, 0.0));
        // rotationMatrix = rotate(rotationMatrix, rotation.z, vec3(0.0, 0.0, 1.0));

        // rotationMatrix = glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);

        needUpdate = true;

        return *this;
    }

    ModelState3D& update()
    {
        if(needUpdate)
        {
            rotationMatrix = glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);
            mat4 scaleMatrix = glm::scale(mat4(1.0), scale);
            mat4 translateMatrix = translate(mat4(1.0), position);

            modelMatrix = translateMatrix * rotationMatrix * scaleMatrix;

            needUpdate = false;
        }

        return *this;
    }   
};

class ModelMatrix3D : mat4
{

    public : 
    
    ModelMatrix3D(ModelState3D state)
    {
        this->update(state);
    }

    ModelMatrix3D& update(ModelState3D state)
    {

        // float mat[16] = 
        // {
        //     state.scale.x   ,  0.f             ,  0.f             ,  0.f,
        //     0.f             ,  state.scale.y   ,  0.f             ,  0.f,
        //     0.f             ,  0.f             ,  state.scale.z   ,  0.f,
        //     state.position.x,  state.position.y,  state.position.z,  0.f
        // };

        // memcpy((void*)this, mat, sizeof(mat4));

        return *this;
    }
};


#endif