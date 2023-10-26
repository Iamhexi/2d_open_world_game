#include "include/Character.hpp"
#include "include/ResourceManager.hpp"
#include "include/Dialogue.hpp"
#include "include/Inventory.hpp"
#include "include/Logger.hpp"

#include <iostream>
#include <filesystem>
#include <sstream>
namespace fs = std::filesystem;

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline (ss, item, delimiter))
        result.push_back (item);

    return result;
}

void loadTextureToTextureManager(
    ResourceManager<sf::Texture>& texturesManager,
    const std::string& textureName,
    const std::string& texturePath
) {
    sf::Texture texture;
    if (!texture.loadFromFile(texturePath)) {
        Logger::getInstance().log(std::string("Loading the ") + textureName + " texture failed.", LogLevel::Warning);
        return;
    }

    texturesManager.set(textureName, texture);
    Logger::getInstance().log( 
        std::string("Properly loaded texture ") + textureName + " from " + texturePath + '.',
        LogLevel::Info
    );
}

void loadTexturesToTextureManager
(
    ResourceManager<sf::Texture>& texturesManager,
    const std::string& textureDirectory
) {
    const fs::path pathToShow{ textureDirectory };

    for (const auto& entry : fs::directory_iterator(pathToShow)) {
        const auto filename = entry.path().filename().string();
        std::string textureName = split(filename, '.').at(0);
        std::string texturePath = textureDirectory + '/' + filename;
        loadTextureToTextureManager(texturesManager, textureName, texturePath);
    }
}

int main()
{
    ResourceManager<sf::Texture> texturesManager;
    ResourceManager<sf::Font> fontsManager;

    std::string textureDirectory = "../resources/textures";
    loadTexturesToTextureManager(texturesManager, textureDirectory);
    Logger::getInstance().printEventLog(LogLevel::Info);

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.antialiasingLevel = 16;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    sf::Font marrada;
    if (!marrada.loadFromFile("../resources/fonts/marrada.ttf"))
        std::cout << "Loading the marrada font failed!\n";

    fontsManager.set(std::string("marrada"), marrada);


    std::string name = "Igor";
    Speaker igor( name, texturesManager.get("hero") );
    igor.addDialogueLine("Hey, how are you?");
    igor.addDialogueLine("What are you doing?");

    std::string name2 = "Krzysztof";
    Speaker igor2( name2, texturesManager.get("pig") );
    igor2.addDialogueLine("Well, I've been waiting for you...");
    igor2.addDialogueLine("Waiting?");

    Dialogue dialogue(window, fontsManager.get("marrada"));
    dialogue.addSpeaker(igor);
    dialogue.addSpeaker(igor2);
    dialogue.start();

    std::vector<std::shared_ptr<Item>> itemsOnMap;
    auto axeLyingAround = std::make_shared<Item>(texturesManager.get("axe"));
    itemsOnMap.push_back(axeLyingAround);


    Character hero(window, texturesManager.get("hero"), sf::Vector2f(500, 200), texturesManager.get("nonExistingItem"));

    Item axe(texturesManager.get("axe"));
    hero.inventory->addItem(axe);

    Logger::getInstance().printEventLog(LogLevel::Info);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        hero.handleMovement();
        hero.handlePickingUpItems(itemsOnMap);
        // hero.handleStartingDialogue(charactersOnMap);
        dialogue.handle();

        window.clear();
        
        for (auto& item: itemsOnMap)
            item->render(window);

        hero.render();
        dialogue.render();

        window.display();
    }

    return 0;
}
