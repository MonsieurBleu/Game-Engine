#ifndef FNCT_NORMAL_MAP_GLSL
#define FNCT_NORMAL_MAP_GLSL

#include functions/FastMaths.glsl

/*
    Source : http://www.thetenthplanet.de/archives/1180
*/

mat3 cotangent_frame( vec3 N, vec3 p, vec2 uv )
{ 
    // get edge vectors of the pixel triangle 
    vec3 dp1 = dFdx( p ); 
    vec3 dp2 = dFdy( p ); 
    vec2 duv1 = dFdx( uv ); 
    vec2 duv2 = dFdy( uv );   
    // solve the linear system 
    vec3 dp2perp = cross( dp2, N ); 
    vec3 dp1perp = cross( N, dp1 ); 
    vec3 T = dp2perp * duv1.x + dp1perp * duv2.x; 
    vec3 B = dp2perp * duv1.y + dp1perp * duv2.y;   
    // construct a scale-invariant frame 
    // float invmax = inversesqrt( max( dot(T,T), dot(B,B) ) ); 
    float invmax = fastinverseSqrt( max( dot(T,T), dot(B,B) ) );
    return mat3( T * invmax, B * invmax, N );
}

#define WITH_NORMALMAP_GREEN_UP

vec3 perturbNormal( vec3 N, vec3 V, vec2 tNormal, vec2 texcoord) 
{ 
    // assume N, the interpolated vertex normal and 
    // V, the view vector (vertex to eye) 
    vec3 map = vec3(tNormal, 0.0); 

    map = map * 255./127. - 128./127.; 

    map.z = sqrt( 1. - dot( map.xy, map.xy ) ); 

    #ifdef WITH_NORMALMAP_GREEN_UP 
    map.y = -map.y; 
    #endif 

    mat3 TBN = cotangent_frame( N, -V, texcoord ); 
    return normalize( TBN * map );
}

#endif
