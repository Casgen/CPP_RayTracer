#pragma once
#include "Aliases.h"

class Ray
{
    Vec3 Origin, Direction = Vec3();

public:
    
    //Constructors
    Ray() = default;
    Ray(const Vec3 &Orig, const Vec3 &Dir)
        : Origin(Orig), Direction(Dir) {}

    //Getters
    Vec3 GetOrigin() const {return Origin;}
    Vec3 GetDirection() const {return Direction;}

    //Setters
    void SetOrigin(const Vec4 &Orig) {Origin = Orig;}
    void SetDirection(const Vec4 &Dir) {Direction = normalize(Dir);}

    //Unique Funcs
    Vec3 At(float t) { return Origin+t*Direction;}
    
};
