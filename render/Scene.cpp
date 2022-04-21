#include "Scene.h"

#include <glm/ext/matrix_projection.hpp>

using namespace glm;

template<typename T>
bool Scene::Hit(Ray& ray, HitRecord& hitRecord)
{
    bool hitAnything = false;
    float closestSoFar = tMax;
    
    if (hittableObjects.capacity() > 0)
    {
        for (HittableObject* object : hittableObjects)
        {

            if (object->TestIntersection(ray, hitRecord, tMin, closestSoFar))
            {
                hitAnything = true;
                closestSoFar = hitRecord.t;
            }
        }
    }
    return hitAnything;
}

template bool Scene::Hit<float>(Ray& ray, HitRecord& hitRecord);
