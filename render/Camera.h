#pragma once
#include <glm/glm.hpp>

#include "../math/Aliases.h"

class Camera
{
private:

    Vec3 Position, ViewDirection, UpVector = Vec4();
    Mat4x4 ViewMat = Mat4x4();

public:
    Camera() = default;
    Camera(Vec4 const &pos, Vec4 const &view, Vec4 const &up);
    
};
