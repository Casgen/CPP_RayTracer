#pragma once
#include <glm/glm.hpp>

using namespace glm;

struct HitRecord
{
   vec3 point;
   vec3 normal;
   float t;
};
