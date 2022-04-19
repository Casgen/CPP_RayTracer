#include "Camera.h"

#include <memory>
#include <glm/ext/matrix_projection.hpp>
#include <glm/ext/matrix_transform.hpp>

using namespace glm;

template<typename NumType>
void Camera::Yaw(NumType azimuth)
{
    this->Azimuth = azimuth;
    CalculateAndSetUpAndViewVector();
    CalculateAndSetViewTransformation();
}

template<typename NumType>
void Camera::Pitch(NumType zenith)
{
    this->Zenith = zenith;
    CalculateAndSetUpAndViewVector();
    CalculateAndSetViewTransformation();
}

template<typename NumType>
Ray Camera::CreateARay(const NumType& x, const NumType& y, const mat4x4& modelMat) 
{
    return Ray(eyePosition,unProject(vec3(x, y, 0.1f), modelMat * viewMat,projectionMatPersp, viewPort));
}

template Ray Camera::CreateARay<float>(const float& x, const float& y, const mat4x4& modelMat);
template Ray Camera::CreateARay<int>(const int& x, const int& y, const mat4x4& modelMat);



void Camera::CalculateAndSetUpAndViewVector()
{
    ViewDirection = vec3(cos(this->Azimuth) * cos(this->Zenith),
                         sin(this->Azimuth) * cos(this->Zenith),
                         sin(this->Zenith));

    UpVector = vec3(cos(this->Azimuth) * cos(this->Zenith + glm::pi<float>() / 2),
                    sin(this->Azimuth) * cos(this->Zenith + glm::pi<float>() / 2),
                    sin(this->Zenith + glm::pi<float>() / 2));
}

void Camera::CalculateAndSetViewTransformation()
{
    viewMat = lookAt(eyePosition, ViewDirection, UpVector);
}

