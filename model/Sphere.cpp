#include "Sphere.h"

bool Sphere::TestIntersection(Ray& ray, HitRecord& hitRecord, float& tMin, float& tMax)
{
    vec3 oc = ray.origin - position;

    const vec3 rayDirection = ray.direction;
    
    float a = pow(length(rayDirection),2); 
    float half_b = dot(oc,rayDirection);
    float c =  pow(length(oc),2) - radius*radius;
    float discriminant = half_b*half_b - a*c;

    if (discriminant < 0)
        return false;

    float sqrtd = sqrt(discriminant);
    
    //Find the nearest root that lies in the acceptable range
    float root = (-half_b - sqrtd) / a;
    if (tMin > root || root > tMax)
    {
        root = (-half_b + sqrtd) / a;
        if (tMin > root || root > tMax) return false;
    }

    hitRecord = HitRecord();
    hitRecord.t = root;
    hitRecord.point = ray.At(root);
    hitRecord.material = this->material;
    
    const vec3 outwardNormal = (hitRecord.point - position) / radius;

    hitRecord.SetFaceNormal(ray,outwardNormal);
    
    return true;
}

