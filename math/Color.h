#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Aliases.h"

struct Color
{
private:
    Vec4 color;

public:
    //Constructors
    Color() = default;
    explicit Color(const Vec4 vec) : color(vec) {}
    Color(float r, float g, float b);
    Color(float r, float g, float b, float a);
    
    //Getters
    Vec4 GetColorRGBA()
    {
        return color;
    }

    //IMPORTANT: Creates a new reference
    Vec3 GetColorRGB() { return {color.r,color.g,color.b}; }

    //Setters

    void SetColor(Vec4 vec) { color = vec; }
    
    //Operator overloads
    Vec4 operator* (const Vec4 &vec) const {return vec*this->color;}
    Vec4 operator+ (const Vec4 &vec) const {return vec+this->color;}
    Vec4 operator- (const Vec4 &vec) const {return this->color-vec;}
    Vec4 operator/ (const Vec4 &vec) const {return this->color/vec;}

    void operator*= (const Vec4 &vec) {this->color = this->color * vec;}
    void operator+= (const Vec4 &vec) {this->color = this->color + vec;}
    void operator-= (const Vec4 &vec) {this->color = this->color - vec;}
    void operator/= (const Vec4 &vec) {this->color = this->color / vec;}

    //Other
    sf::Color AsSFColor() const
    {
        return {uint8_t(color.r*255),uint8_t(color.g*255),uint8_t(color.b*255)};
    }
};
