#pragma once
#include <glm/glm.hpp>

using namespace glm;

class Ray
{
    vec3 Origin, Direction = vec3();

public:
    
    //Constructors
    Ray() = default;
    Ray(const vec3 &Orig, const vec3 &Dir)
        : Origin(Orig), Direction(normalize(Dir)) {}

    //Getters
    vec3 GetOrigin() const {return Origin;}
    vec3 GetDirection() const {return Direction;}

    //Setters
    void SetOrigin(const vec4 &Orig) {Origin = Orig;}
    void SetDirection(const vec4 &Dir) {Direction = normalize(Dir);}

    //Unique Funcs
    vec3 At(float t) { return Origin+t*Direction;}
    void ToString();
    
};
