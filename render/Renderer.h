#pragma once
#include "Scene.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <SFML/Graphics/Image.hpp>
#include <glm/ext/matrix_projection.hpp>

class Renderer
{
    Scene scene;
    float Height, Width;
    sf::Image ImageBuffer;
    Mat4x4 ModelMat = Mat4x4(1.0f);
    Mat4x4 ProjectionMatPersp;
    Mat4x4 ProjectionMatOrtho = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);

public:
    //Constructors
    Renderer(Scene& sc, const float h, const float w)
        : scene(sc), Height(h), Width(w), ImageBuffer(sf::Image()), ModelMat(Mat4x4()),
          ProjectionMatPersp(glm::perspective(glm::radians<float>(45.0f), Width / Height, 0.1f, 100.f))
    {
        ImageBuffer.create(w,h);
    }

    //Getters
    float GetHeight() const { return Height; }
    float GetWidth() const { return Width; }

    //Unique Funcs
    void Render();
};
