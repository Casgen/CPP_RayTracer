#include "Camera.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
Camera::Camera(Vec4 const& pos, Vec4 const& view, Vec4 const& up)
    : Position(pos), ViewDirection(view), UpVector(up)
{
    
}

