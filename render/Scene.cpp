#include "Scene.h"

#include <glm/ext/matrix_projection.hpp>

using namespace glm;

template<typename T>
bool Scene::SendARay(Ray& ray, const T& x, const T& y, HitRecord& hitRecord)
{
    if (hittableObjects.capacity() > 0)
    {
        for (HittableObject* object : hittableObjects)
        {
            ray = cam.CreateARay(x, y);
            hitRecord = HitRecord();

            if (object->TestIntersection(ray, hitRecord, 0.f, 10.f))
                return true;

            return false;
        }
    }
    return false;
}

template bool Scene::SendARay<float>(Ray& ray, const float& x, const float& y, HitRecord& hitRecord);
