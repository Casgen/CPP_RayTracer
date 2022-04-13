#pragma once

#include <glm/glm.hpp>
#include "../math/Color.h"
#include "../math/Ray.h"

class HittableObject
{
private:
    vec4 Position = vec4();
    mat4x4 TransformMat = mat4x4(1);
    Color color = Color();
    
public:
    
    //Constructors
    HittableObject() = default;
    HittableObject(const vec4 pos, const Color col) : Position(pos), TransformMat(mat4x4()), color(col) {}
    
    // Getters
    vec4 GetPosition() const {return Position;}
    mat4x4 GetTransformMat() const {return TransformMat;}

    //Setters
    void SetPosition(const vec4 pos) {Position = vec4(pos);}
    void Translate(vec3 trans);

    //Unique Funcs
    virtual void TestIntersection(const Ray& ray);
};
