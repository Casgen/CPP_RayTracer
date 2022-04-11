#pragma once

#include <glm/glm.hpp>
#include "../math/Color.h"
#include "../math/Aliases.h"
#include "../math/Ray.h"

class HittableObject
{
private:
    Vec4 Position = Vec4();
    Mat4x4 TransformMat = Mat4x4(1);
    Color color = Color();
    
public:
    
    //Constructors
    HittableObject() = default;
    HittableObject(const Vec4 pos, const Color col) : Position(pos), TransformMat(Mat4x4()), color(col) {}
    
    // Getters
    Vec4 GetPosition() const {return Position;}
    Mat4x4 GetTransformMat() const {return TransformMat;}

    //Setters
    void SetPosition(const Vec4 pos) {Position = Vec4(pos);}
    void Translate(Vec3 trans);

    //Unique Funcs
    virtual void TestIntersection(const Ray& ray);
};
