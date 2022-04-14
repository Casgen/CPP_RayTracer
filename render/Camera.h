#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

using namespace glm;

class Camera
{
    vec3 EyePosition; 
    vec3 ViewDirection;
    vec3 UpVector;
    mat4x4 ViewMat;
    float Azimuth, Zenith;

public:
    //------Constructors------

    Camera() : EyePosition(vec3(0.f,0.f,0.f)), Azimuth(0), Zenith(0)
    {
        CalculateUpAndViewVector();
        CalculateViewTransformation();
    }
    
    /**
     * Creates a Camera and it's view transformation matrix
     * @param Pos Position of the Camera
     */
    Camera(vec3 const& Pos)
        : EyePosition(Pos), Azimuth(0), Zenith(0)
    {
        CalculateUpAndViewVector();
        CalculateViewTransformation();
    }

    //------------------------

    //--------Getters---------

    vec3 GetEyePosition() const { return EyePosition; }
    vec3 GetViewDirection() const { return ViewDirection; }
    vec3 GetUpVector() const { return UpVector; }
    mat4x4 GetViewMat() const { return ViewMat; }

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
