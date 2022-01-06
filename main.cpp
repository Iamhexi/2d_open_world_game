#include "Character.hpp"
#include "ResourceManager.hpp"
#include "Dialogue.hpp"
#include <iostream>

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

    std::string name = "Igor";
    Speaker igor( name, texturesManager.get("hero") );
    igor.addDialogueLine("Hey, how are you?");
    igor.addDialogueLine("What are you doing>");

    std::string name2 = "Igor2";
    Speaker igor2( name2, texturesManager.get("hero") );
    igor2.addDialogueLine("DUPA DUPA DUPA");
    igor2.addDialogueLine("LA LA LA DUPA DUPA");

    Dialogue dialogue(window, fontsManager.get("marrada"));
    dialogue.addSpeaker(igor);
    dialogue.addSpeaker(igor2);
    dialogue.start();

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
        dialogue.handle();

        window.clear();

        hero.render();
        dialogue.render();

        window.display();
    }

    return 0;
}
