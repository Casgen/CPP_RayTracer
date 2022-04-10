#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "../math/Aliases.h"

class Camera
{
private:

    Vec3 EyePosition, ViewDirection, UpVector = Vec4();
    Mat4x4 ViewMat = Mat4x4();

public:

    //Constructors
    Camera() = default;
    /**
     * Creates a Camera and it's view transformation matrix
     * @param Pos Position of the Camera
     * @param View A direction which camera points to
     * @param Up Vector that points upward from the camera (assigns roll to the camera)
     */
    Camera(Vec3 const &Pos, Vec3 const &View, Vec3 const &Up)
    : EyePosition(Pos), ViewDirection(View), UpVector(Up), ViewMat(lookAt(Pos,View,Up)) {}

    
};
