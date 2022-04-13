#pragma once
#include "Scene.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <SFML/Graphics/Image.hpp>
#include <glm/ext/matrix_projection.hpp>

using namespace glm;

class Renderer
{
    Scene scene;
    float Height, Width;
    sf::Image ImageBuffer;

    ivec4 ViewPort;
    mat4x4 ModelMat;
    mat4x4 ProjectionMatPersp;
    mat4x4 ProjectionMatOrtho = ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);

public:
    //Constructors
    Renderer(Scene& sc, const float h, const float w)
        : scene(sc), Height(h), Width(w), ImageBuffer(sf::Image()), ViewPort(ivec4(0,0,w,h)), ModelMat(mat4x4(1.0f)),
          ProjectionMatPersp(perspective(radians<float>(45.0f), Width / Height, 0.1f, 100.f))
    {
        ImageBuffer.create(w,h);
    }

    //Getters
    float GetHeight() const { return Height; }
    float GetWidth() const { return Width; }
    sf::Image* GetImage() {return &ImageBuffer; }

    //Unique Funcs
    void Render();
};
