#include "Sphere.h"

float Sphere::TestIntersection(const Ray& ray)
{
    vec3 oc = ray.GetOrigin() - position;

    vec3 rayDirection = ray.GetDirection();
    
    float a = dot(rayDirection,rayDirection); 
    float b = 2.0f * dot(oc, rayDirection);
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*a*c;

    if (discriminant < 0)
        return -1.0;
    
    return (-b - sqrt(discriminant) ) / (2.0*a);
}

