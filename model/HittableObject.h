#pragma once

#include <memory>
#include <glm/glm.hpp>
#include "../math/Color.h"
#include "../math/Ray.h"
#include "HitRecord.h"

class HittableObject
{
protected:
    vec3 position = vec3();
    mat4x4 transformMat = mat4x4(1);
    Color color = Color();
    
public:
    
    //Constructors
    HittableObject() = default;
    HittableObject(const vec3 pos, const Color col) : position(pos), transformMat(mat4x4()), color(col) {}
    
    // Getters
    vec3 GetPosition() const {return position;}
    mat4x4 GettransformMat() const {return transformMat;}
    Color GetColor() const {return color;}
    //Setters
    void SetPosition(const vec4 pos) {position = vec4(pos);}
    void Translate(vec3 trans);

    //Unique Funcs
    virtual bool TestIntersection(Ray& ray, HitRecord& hitRecord, float tMin, float tMax);
};
