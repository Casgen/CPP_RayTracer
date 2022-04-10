#include "Color.h"

Color::Color(const float r, const float g, const float b) :
color(Vec4(glm::clamp<float>(r,0.,1.),
        glm::clamp<float>(g,0.,1.),
        glm::clamp<float>(b,0.,1.),
        1.))
{
    
}

Color::Color(const float r, const float g, const float b, const float a) :
color(Vec4(glm::clamp<float>(r,0.,1.),
            glm::clamp<float>(g,0.,1.),
            glm::clamp<float>(b,0.,1.),
            glm::clamp<float>(a,0.,1.)))
{
    
}
