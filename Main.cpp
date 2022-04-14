#include <SFML/Graphics.hpp>
#include "math/Color.h"
#include "model/Sphere.h"
#include "render/Renderer.h"

static int width = 800;
static int height = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    Camera camera = Camera();
    Scene scene = Scene(camera);
    Sphere sphere = Sphere(vec3(1.f, 0.f, 0.f), Color(0.5f, 0.468f, 0.89f), 0.07f);
    scene.AddHittableObject(&sphere);

    sf::Image img = sf::Image();
    Renderer renderer = Renderer(scene, height, width, img);

    /*sf::Vector2u Size = renderer.GetImage().getSize();

    for (uint32_t y = 0; y < Size.y; y++)
    {
        for (uint32_t x = 0; x < Size.x; x++)
        {
            Color color = Color(x/(float)Size.y,y/(float)Size.y,0);
            img.setPixel(x,y,color.AsSFColor());
        }        
    }*/


    renderer.Render();
    
    sf::Texture MainTexture;
    MainTexture.loadFromImage(img);

    sf::Sprite Sprite(MainTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(Sprite);
        window.display();
    }

    return 0;
}
