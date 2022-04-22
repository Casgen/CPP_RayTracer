#include "Sphere.h"

#include "../math/MathUtils.h"

bool Sphere::TestIntersection(Ray& ray, HitRecord& hitRecord, float& tMin, float& tMax)
{
    vec3 oc = ray.origin - position;

    float a = MathUtils::VectorLengthSquared(ray.direction); 
    float half_b = dot(oc,ray.direction);
    float c =  MathUtils::VectorLengthSquared(oc) - radius*radius;
    float discriminant = half_b*half_b - a*c;

    if (discriminant < 0)
        return false;

    float sqrtd = sqrt(discriminant);
    
    //Find the nearest root that lies in the acceptable range
    float root = (-half_b - sqrtd) / a;
    if (root < tMin || tMax < root)
    {
        root = (-half_b + sqrtd) / a;
        if (root < tMin || tMax < root)
            return false;
    }

    hitRecord = HitRecord();
    hitRecord.t = root;
    hitRecord.point = ray.At(root);
    hitRecord.material = this->material;
    
    const vec3 outwardNormal = (hitRecord.point - position) / radius;

    hitRecord.SetFaceNormal(ray,outwardNormal);
    
    return true;
}

