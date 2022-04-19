#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <SFML/Graphics/Color.hpp>

using namespace glm;

struct Color
{
private:
    vec4 color = vec4();

public:
    //Constructors
    Color() = default;
    explicit Color(const vec4 vec) : color(vec) {}
    Color(float r, float g, float b);
    Color(float r, float g, float b, float a);
    
    //Getters
    vec4 GetColorRGBA()
    {
        return color;
    }

    //IMPORTANT: Creates a new reference
    vec3 GetColorRGB() { return {color.r,color.g,color.b}; }

    //Setters

    void SetColor(vec4 vec) { color = vec; }
    
    //Operator overloads
    vec4 operator* (const vec4& vec) const {return vec*this->color;}
    vec4 operator+ (const vec4& vec) const {return vec+this->color;}
    vec4 operator- (const vec4& vec) const {return this->color-vec;}
    vec4 operator/ (const vec4& vec) const {return this->color/vec;}

    void operator*= (const vec4& vec) {this->color = this->color * vec;}
    void operator+= (const vec4& vec) {this->color = this->color + vec;}
    void operator-= (const vec4& vec) {this->color = this->color - vec;}
    void operator/= (const vec4& vec) {this->color = this->color / vec;}

    Color operator* (Color& vec) const {return Color(this->color*vec.GetColorRGBA());}
    Color operator+ (Color& vec) const {return Color(this->color+vec.GetColorRGBA());}
    Color operator- (Color& vec) const {return Color(this->color-vec.GetColorRGBA());}
    Color operator/ (Color& vec) const {return Color(this->color/vec.GetColorRGBA());}

    void operator*= (Color& vec) {this->color = this->color * vec.GetColorRGBA();}
    void operator+= (Color& vec) {this->color = this->color + vec.GetColorRGBA();}
    void operator-= (Color& vec) {this->color = this->color - vec.GetColorRGBA();}
    void operator/= (Color& vec) {this->color = this->color / vec.GetColorRGBA();}

    template<typename NumType>
    Color operator* (NumType& f) const {return Color(this->color*f);}

    template<typename NumType>
    Color operator+ (NumType& f) const {return Color(this->color+f);}

    template<typename NumType>
    Color operator- (NumType& f) const {return Color(this->color-f);}

    template<typename NumType>
    Color operator/ (NumType& f) const {return Color(this->color/f);}
    
    template<typename NumType>
    void operator*= (NumType& num) {this->color = this->color * num;}

    template<typename NumType>
    void operator+= (NumType& num) {this->color = this->color + num;}

    template<typename NumType>
    void operator-= (NumType& num) {this->color = this->color - num;}

    template<typename NumType>
    void operator/= (NumType& num) {this->color = this->color / num;}
    
    //Other
    sf::Color AsSFColor() const
    {
        return {uint8_t(color.r*255),uint8_t(color.g*255),uint8_t(color.b*255)};
    }
};
