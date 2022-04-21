#pragma once

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
    std::shared_ptr<Material> material;
    
public:
    
    //Constructors
    HittableObject() = default;
    HittableObject(const vec3 pos, const Color col, const std::shared_ptr<Material> mat)
    : position(pos), transformMat(mat4x4()), color(col), material(mat) {}
    
    // Getters
    [[nodiscard]] vec3 GetPosition() const {return position;}
    [[nodiscard]] mat4x4 GetTransformMat() const {return transformMat;}
    [[nodiscard]] Color GetColor() const {return color;}
    //Setters
    void SetPosition(const vec4 pos) {position = vec4(pos);}
    void Translate(vec3 trans);

    //Unique Funcs
    virtual bool TestIntersection(Ray& ray, HitRecord& hitRecord, float& tMin, float& tMax);
};
