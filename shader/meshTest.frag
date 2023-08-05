#version 460

#include include/uniform/Base3D.glsl
#include include/uniform/Model3D.glsl

in vec3 color;
in vec3 normal;
in vec3 position;

#include include/globals/Fragment3DOutputs.glsl

void main()
{
    fragColor = vec4(color, 1.0);
    fragNormal = normal;
    fragAlbedo =  vec3(1.0);
    fragPosition = (vec4(position, 1.0)*_cameraViewMatrix);
};