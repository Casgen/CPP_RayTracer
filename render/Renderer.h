#pragma once
#include "Scene.h"
#include <SFML/Graphics/Image.hpp>
#include <glm/ext/matrix_projection.hpp>

using namespace glm;

class Renderer
{
    Scene& scene;
    float Height, Width;
    sf::Image& ImageBuffer;
    float sampling = 64;
    int rayRecursionDepth = 4;
    ivec4 viewPort;

public:
    //Constructors
    /**
     *  Constructs a renderer
     *  @param sc - A scene which renderer will work with
     *  @param h - Height of a Window (viewport)
     *  @param w - Width of a window (viewport)
     *  @param img - An image to output the render the results to
     */
    template<typename NumType>
    Renderer(Scene& sc, const NumType h, const NumType w, sf::Image& img )
        : scene(sc), Height(h), Width(w), ImageBuffer(img), viewPort(ivec4(0,0,w,h))
    {
        ImageBuffer.create(w,h);
    }

    //Getters
    float GetHeight() const { return Height; }
    float GetWidth() const { return Width; }
    [[nodiscard]] const sf::Image& GetImage() const {return ImageBuffer; }

    //Unique Funcs
    
    /**
     *  Renders an image by it's scene
     */
    void Render();
    Color ColorRay(int& x, int& y, Ray& ray, const int& depth);
};
