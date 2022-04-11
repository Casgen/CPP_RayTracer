#include "Camera.h"

using namespace glm;

void Camera::Yaw(float azimuth)
{
    this->Azimuth = azimuth;
    CalculateUpAndViewVector();
    CalculateViewTransformation();
}

void Camera::Pitch(float zenith)
{
    this->Zenith = zenith;
    CalculateUpAndViewVector();
    CalculateViewTransformation();
}

void Camera::CalculateUpAndViewVector()
{
    ViewDirection = Vec3(cos(this->Azimuth) * cos(this->Zenith),
                         sin(this->Azimuth) * cos(this->Zenith),
                         sin(this->Zenith));

    UpVector = Vec3(cos(this->Azimuth) * cos(this->Zenith + glm::pi<float>() / 2),
                    sin(this->Azimuth) * cos(this->Zenith + glm::pi<float>() / 2),
                    sin(this->Zenith + glm::pi<float>() / 2));
}

void Camera::CalculateViewTransformation()
{
    ViewMat = lookAt(EyePosition, ViewDirection, UpVector);
}
