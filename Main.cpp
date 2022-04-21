#include <thread>
#include <SFML/Graphics.hpp>
#include "math/Color.h"
#include "model/Lambertian.h"
#include "model/Metal.h"
#include "model/Sphere.h"
#include "render/Renderer.h"

static int width = 800;
static int height = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    Camera camera = Camera(static_cast<float>(width), static_cast<float>(height));
    Scene scene = Scene(camera);

    /**
     * Very fishy is something going on here when using the Release build. When i create the spheres directly in the
     * AddHittableObject() the spheres are pointing to the same memory address. That means that one object acts
     * as the other one (It acts as a copy). Maybe it relates to the way the signature of the method is written?
     * (rvalue vs. lvalue)
     */


    Sphere leftSphere = Sphere(vec3(1.f, 0.3f, 0.f), Color(0.5f, 0.468f, 0.89f), 0.15f,
                              std::make_shared<Metal>(Color(0.156f, 0.8f, 0.214f)));
    
    Sphere rightSphere = Sphere(vec3(1.f, -0.3f, 0.f), Color(0.5f, 0.468f, 0.89f), 0.15f,
                              std::make_shared<Metal>(Color(0.487f, 0.214f, 0.874f)));
    
    Sphere middleSphere = Sphere(vec3(1.f, 0.f, 0.f), Color(0.5f, 0.468f, 0.89f), 0.15f,
                              std::make_shared<Metal>(Color(0.f, 0.7f, 0.7f)));
    
    Sphere bottomSphere = Sphere(vec3(1.f, 0.f, 3.2f), Color(0.5f, 0.468f, 0.89f), 3.f,
                                 std::make_shared<Lambertian>(Color(0.8f, 0.8f, 0.f)));
    scene.AddHittableObject(&rightSphere);
    scene.AddHittableObject(&leftSphere);
    scene.AddHittableObject(&middleSphere);
    scene.AddHittableObject(&bottomSphere);

    sf::Image img = sf::Image();
    Renderer renderer = Renderer(scene, height, width, img);

    std::thread worker = std::thread(&Renderer::Render, &renderer);

    while (window.isOpen())
    {
        sf::Event event = sf::Event();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                worker.join();
                window.close();
            }
        }

        sf::Texture MainTexture;
        MainTexture.loadFromImage(img);

        sf::Sprite Sprite(MainTexture);

        window.clear();
        window.draw(Sprite);
        window.display();
    }

    return 0;
}
