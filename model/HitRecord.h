#pragma once
#include <glm/glm.hpp>

class Ray;
using namespace glm;

struct HitRecord
{
   vec3 point = vec3();
   vec3 normal = vec3();
   float t;
   bool frontFace = false;
   
   HitRecord() = default;

   void SetFaceNormal(const Ray& ray, const vec3& outwardNormal);
   
};
