#include "HitRecord.h"

#include "../math/Ray.h"

void HitRecord::SetFaceNormal(const Ray& ray, const vec3& outwardNormal)
{
    frontFace = dot(ray.direction, outwardNormal) < 0;
    normal = frontFace ? outwardNormal : -outwardNormal;
}

