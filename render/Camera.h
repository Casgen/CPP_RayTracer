#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "../math/Aliases.h"

class Camera
{
    Vec3 EyePosition, ViewDirection, UpVector = Vec3();
    Mat4x4 ViewMat = Mat4x4();
    float Azimuth, Zenith;

public:
    //------Constructors------

    /**
     * Creates a Default camera (All coords initialized to zero).
     */
    Camera() = default;

    /**
     * Creates a Camera and it's view transformation matrix
     * @param Pos Position of the Camera
     * @param View A direction which camera points to
     * @param Up Vector that points upward from the camera (assigns roll to the camera)
     */
    Camera(Vec3 const& Pos, Vec3 const& View, Vec3 const& Up)
        : EyePosition(Pos), ViewDirection(normalize(View)), UpVector(normalize(Up)),
          ViewMat(lookAt(Pos, normalize(View), normalize(Up))), Azimuth(0), Zenith(0)
    {
        
    }

    //------------------------

    //--------Getters---------

    Vec3 GetEyePosition() const { return EyePosition; }
    Vec3 GetViewDirection() const { return ViewDirection; }
    Vec3 GetUpVector() const { return UpVector; }
    Mat4x4 GetViewMat() const { return ViewMat; }

    //------------------------

    
    //----Transformations-----
    
    void Yaw(float azimuth);
    void Pitch(float zenith);

    //------------------------

private:
    
    //----Transformations-----
    
    void CalculateUpAndViewVector();
    void CalculateViewTransformation();

    //------------------------
};
