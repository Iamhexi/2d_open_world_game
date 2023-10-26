#pragma once
#include "Item.hpp"
#include "Character.hpp"
#include "ResourceManager.hpp"
#include "Dialogue.hpp"
#include "Inventory.hpp"
#include "Logger.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

class Scene {

public:
    Scene(sf::Vector2i windowSize);
    void init();
    void run();

private:
    void initWindow();

private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Vector2i windowSize;

    ResourceManager<sf::Texture> texturesManager;
    ResourceManager<sf::Font> fontsManager;

    std::vector<std::shared_ptr<Item>> itemsOnMap;

    std::unique_ptr<Character> hero;
    std::vector<std::shared_ptr<Character>> otherCharactersOnMap;
};