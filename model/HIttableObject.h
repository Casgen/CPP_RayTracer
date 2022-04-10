#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "../math/Aliases.h"

class HittableObject
{
private:
    Vec4 Position = Vec4();
    Mat4x4 TransformMat = Mat4x4();
    
public:
    HittableObject() = default;
    HittableObject(const Vec4 Pos) : Position(Pos), TransformMat(Mat4x4()) {}

    
    // Getters
    Vec4 GetPosition() const {return Position;}
    Mat4x4 GetTransformMat() const {return TransformMat;}

    //Setters
    void SetPosition(const Vec4 Pos) {Position = Vec4(Pos);}
};
