#pragma once
#include "HittableObject.h"

class Sphere : public HittableObject
{
    float Radius = 0;

public:
    Sphere() = default;
    Sphere(const vec4 center, const Color col, const float r)
        : HittableObject(center, col), Radius(r) {}
    //Getters
    float GetRadius() const {return Radius;}

    //Setters
    void SetRadius(float radius) {Radius = radius;}

    void TestIntersection(const Ray& ray) override;
};
