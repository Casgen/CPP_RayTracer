#pragma once
#include <memory>
#include <glm/glm.hpp>
#include "Material.h"
#include "../math/Ray.h"

using namespace glm;

struct HitRecord
{
   vec3 point = vec3();
   vec3 normal = vec3();
   float t;
   std::shared_ptr<Material> material;
   bool frontFace = false;
   
   HitRecord() = default;

   void SetFaceNormal(const Ray& ray, const vec3& outwardNormal);
   
};
