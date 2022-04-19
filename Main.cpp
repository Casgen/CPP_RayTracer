#include <thread>
#include <SFML/Graphics.hpp>
#include "math/Color.h"
#include "model/Sphere.h"
#include "render/Renderer.h"

static int width = 800;
static int height = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    Camera camera = Camera(static_cast<float>(width),static_cast<float>(height));
    Scene scene = Scene(camera);
    Sphere sphere = Sphere(vec3(1.f, 0.f, 0.f), Color(0.5f, 0.468f, 0.89f), 0.27f);
    scene.AddHittableObject(&sphere);

    sf::Image img = sf::Image();
    Renderer renderer = Renderer(scene, height, width, img);
    
    std::thread worker = std::thread(&Renderer::Render,&renderer);
    
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
