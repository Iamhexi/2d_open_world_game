#include "Character.hpp"
#include "ResourceManager.hpp"
#include <iostream>

// TODO: Dialogue class

int main()
{
    ResourceManager<sf::Texture> texturesManager;
    ResourceManager<sf::Font> fontsManager;

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.antialiasingLevel = 16;


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    {
        sf::Texture heroTexture;
        if (!heroTexture.loadFromFile("resources/textures/hero.png"))
            std::cout << "Loading the hero texture failed!\n";

        texturesManager.set("hero", heroTexture);
    }

    {
        sf::Font marrada;
        if (!marrada.loadFromFile("resources/fonts/Marrada.ttf"))
            std::cout << "Loading the Marrada font failed!\n";

        fontsManager.set(std::string("marrada"), marrada);
    }


    Character hero(window, texturesManager.get("hero"), sf::Vector2f(500, 500));

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

        hero.draw();

        window.display();
    }

    return 0;
}
