#include "HittableObject.h"

#include <memory>

void HittableObject::Translate(vec3 trans)
{
    
}


bool HittableObject::TestIntersection(Ray& ray, HitRecord&, float tMin, float tMax)
{
    return false;
}
