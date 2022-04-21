#pragma once
#include "HitRecord.h"
#include "HittableObject.h"

class Sphere : public HittableObject
{
    float radius = 0;

public:
    Sphere() = default;
    Sphere(const vec3 center, const Color col, const float r, const std::shared_ptr<Material> mat)
        : HittableObject(center, col, mat), radius(r) {}
    
    //Getters
    float GetRadius() const {return radius;}

    //Setters
    void SetRadius(float const r) {radius = r;}

    bool TestIntersection(Ray& ray, HitRecord& hitRecord, float& tMin, float& tMax) override;
};
