#include "Character.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    sf::Texture heroTexture;
    if (!heroTexture.loadFromFile("resources/textures/hero.png"))
        std::cout << "Loading the hero texture failed!\n";

    sf::Sprite sprite;
    sprite.setTexture(heroTexture);
    sprite.setPosition(0, 200);

    Character hero(window, heroTexture, sf::Vector2f(500, 500));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        hero.handleMovement();

        window.clear();

        window.draw(sprite);
        hero.draw();

        window.display();
    }

    return 0;
}
