#pragma once
#include <glm/common.hpp>
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

    /**
     * Creates a Color object with 0. values
     */
    Color() = default;

    /**
     * Creates Color based on glm::vec4
     * @param vec - A glm::vec3 object
     */
    explicit Color(const vec4 vec) : color(vec)
    {
    }

    /**
     * Creates a Color by a scalar
     * @param f - A scalar value
     */
    Color(const float f) : color(vec4(clamp(f, 0.f, 1.f)))
    {
    }

    /**
     * Creates a Color with RGBA values (the color only takes values from 0 to 1)
     */
    Color(const float r, const float g, const float b) :
        color(vec4(glm::clamp<float>(r, 0.f, 1.f),
                   glm::clamp<float>(g, 0.f, 1.f),
                   glm::clamp<float>(b, 0.f, 1.f),
                   1.f))
    {
    }

    /**
     * Creates a Color with RGBA values (the color only takes values from 0 to 1)
     */
    Color(const float r, const float g, const float b, const float a) :
        color(vec4(clamp<float>(r, 0.f, 1.f),
                   clamp<float>(g, 0.f, 1.f),
                   clamp<float>(b, 0.f, 1.f),
                   clamp<float>(a, 0.f, 1.f)))
    {
    }

    //Getters
    vec4 GetColorRGBA() { return color; }

    //IMPORTANT: Creates a new reference
    vec3 GetColorRGB() { return {color.r, color.g, color.b}; }

    //Setters

    void SetColor(vec4 vec) { color = vec; }

    //Operator overloads
    vec4 operator*(const vec4& vec) const { return vec * this->color; }
    vec4 operator+(const vec4& vec) const { return vec + this->color; }
    vec4 operator-(const vec4& vec) const { return this->color - vec; }
    vec4 operator/(const vec4& vec) const { return this->color / vec; }

    void operator*=(const vec4& vec) { this->color = this->color * vec; }
    void operator+=(const vec4& vec) { this->color = this->color + vec; }
    void operator-=(const vec4& vec) { this->color = this->color - vec; }
    void operator/=(const vec4& vec) { this->color = this->color / vec; }

    Color operator*(Color&& vec) const { return Color(this->color * vec.GetColorRGBA()); }
    Color operator+(Color&& vec) const { return Color(this->color + vec.GetColorRGBA()); }
    Color operator-(Color&& vec) const { return Color(this->color - vec.GetColorRGBA()); }
    Color operator/(Color&& vec) const { return Color(this->color / vec.GetColorRGBA()); }

    void operator*=(Color&& vec) { this->color = this->color * vec.GetColorRGBA(); }
    void operator+=(Color&& vec) { this->color = this->color + vec.GetColorRGBA(); }
    void operator-=(Color&& vec) { this->color = this->color - vec.GetColorRGBA(); }
    void operator/=(Color&& vec) { this->color = this->color / vec.GetColorRGBA(); }

    Color operator*(const float& f) const { return Color(this->color * f); }
    Color operator+(const float& f) const { return Color(this->color + f); }
    Color operator-(const float& f) const { return Color(this->color - f); }
    Color operator/(const float& f) const { return Color(this->color / f); }

    void operator*=(const float& f) { this->color *= f; }
    void operator+=(const float& f) { this->color = this->color + f; }
    void operator-=(const float& f) { this->color = this->color - f; }
    void operator/=(const float& f) { this->color = this->color / f; }

    //Other
    [[nodiscard]] sf::Color AsSFColor() const
    {
        return {uint8_t(color.r * 255), uint8_t(color.g * 255), uint8_t(color.b * 255)};
    }
};
