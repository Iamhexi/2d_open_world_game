#pragma once
#include "Item.hpp"
#include "NPC.hpp"
#include "Player.hpp"
#include "ResourceManager.hpp"
#include "DialogueManager.hpp"
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
    void loadTextures();
    void loadFonts();
    void loadDialogues();

private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Vector2i windowSize;

    ResourceManager<sf::Texture> textureManager;
    ResourceManager<sf::Font> fontManager;
    std::shared_ptr<DialogueManager> dialogueManager;

    std::vector<std::shared_ptr<Item>> itemsOnMap;

    std::unique_ptr<Player> hero;
    std::vector<std::shared_ptr<NPC>> NPCs;
};