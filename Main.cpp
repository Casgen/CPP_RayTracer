#include <SFML/Graphics.hpp>

#include "math/Color.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    sf::Image MainImg;
    MainImg.create(800,600);

    sf::Vector2u Size = MainImg.getSize();
    
    for (uint32_t y = 0; y < Size.y; y++)
    {
        for (uint32_t x = 0; x < Size.x; x++)
        {
            Color color = Color(x/(float)Size.y,y/(float)Size.y,0);
            MainImg.setPixel(x,y,color.AsSFColor());
        }        
    }
    
    
    sf::Texture MainTexture;
    MainTexture.loadFromImage(MainImg);
    
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
