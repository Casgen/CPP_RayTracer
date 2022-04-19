#pragma once
#include <glm/glm.hpp>

using namespace glm;

struct Ray
{
    vec3 origin, direction = vec3();
    
    //Constructors
    Ray() = default;
    Ray(const vec3 &Orig, const vec3 &Dir)
        : origin(Orig), direction(normalize(Dir)) {}

    //Getters
    vec3 GetOrigin() const {return origin;}
    vec3 GetDirection() const {return direction;}

    //Setters
    void SetOrigin(const vec4 &Orig) {origin = Orig;}
    void SetDirection(const vec4 &Dir) {direction = normalize(Dir);}

    //Unique Funcs
    vec3 At(float t) { return origin+t*direction;}
    void ToString();
    
};
