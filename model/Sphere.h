#pragma once
#include "HittableObject.h"

class Sphere : public HittableObject
{
    float radius = 0;

public:
    Sphere() = default;
    Sphere(const vec3 center, const Color col, const float r)
        : HittableObject(center, col), radius(r) {}
    //Getters
    float Getradius() const {return radius;}

    //Setters
    void Setradius(float const r) {radius = r;}

    float TestIntersection(const Ray& ray) override;
};
