vec3 lightDirection = normalize(vec3(-1.0, 1.0, 1.0));
vec3 ambientLight = vec3(0.5);

#define DIFFUSE
float diffuseIntensity = 0.40;
vec3 diffuseColor = vec3(1.0);

#define SPECULAR
float specularIntensity = 0.25;
vec3 specularColor = vec3(1.0);

#define RIM
float rimIntensity = 0.35;
vec3 rimColor = vec3(1.0);
