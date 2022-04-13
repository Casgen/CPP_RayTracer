#include <SFML/Graphics.hpp>
#include "math/Color.h"
#include "render/Renderer.h"

static int width = 800;
static int height = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
    
    Camera camera = Camera();
    Scene scene = Scene(camera);
    
    Renderer renderer = Renderer(scene,height,width);

    sf::Vector2u Size = renderer.GetImage()->getSize();
    
    /*for (uint32_t y = 0; y < Size.y; y++)
    {
        for (uint32_t x = 0; x < Size.x; x++)
        {
            Color color = Color(x/(float)Size.y,y/(float)Size.y,0);
            MainImg.setPixel(x,y,color.AsSFColor());
        }        
    }*/
    
    
    sf::Texture MainTexture;
    MainTexture.loadFromImage(*renderer.GetImage());
    
    sf::Sprite Sprite(MainTexture);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderer.Render();
        
        window.clear();
        window.draw(Sprite);
        window.display();
    }

    return 0;
}
