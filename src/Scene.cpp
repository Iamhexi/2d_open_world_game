#include "../include/Scene.hpp"

Scene::Scene(sf::Vector2i windowSize): windowSize(windowSize) {}

void Scene::init() {
    try {

    // Order is VERY important.
    initWindow(); 
    loadFonts();
    loadTextures();
    loadDialogues();

    Character::notExistingItemTexture = std::make_shared<sf::Texture>(textureManager.get("nonExistingItem"));

    itemsOnMap.emplace_back( std::make_shared<Item>(
        textureManager.get("axe"),
        sf::FloatRect(0, 0, window->getSize().x - textureManager.get("axe").getSize().x, window->getSize().y - 540 ) 
    ) );

    hero = std::make_unique<Player>(
        *window,
        textureManager.get("hero"),
        sf::Vector2f(500, 200)
    );

    Item axe(textureManager.get("axe"));
    hero->inventory->addItem(axe);

    Item hammer(textureManager.get("hammer"));
    hero->inventory->addItem(hammer);

    NPCs.emplace_back(
        std::make_shared<NPC>(
            *window,
            textureManager.get("pig"),
            sf::Vector2f(200, 200),
            dialogueManager->get("pig")
        )
    );

    NPCs.emplace_back(
        std::make_shared<NPC>(
            *window,
            textureManager.get("farmer"),
            sf::Vector2f(500, 200),
            dialogueManager->get("farmer")
        )
    );

    NPCs.emplace_back(
        std::make_shared<NPC>(
            *window,
            textureManager.get("king_nose"),
            sf::Vector2f(700, 100),
            dialogueManager->get("king_nose")
        )
    );

    Logger::getInstance().printEventLog(LogLevel::Info);

    } catch(std::string exception) {
        std::cout << exception << std::endl;
        Logger::getInstance().printEventLog(LogLevel::Debug);
    }
}

void Scene::initWindow() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.antialiasingLevel = 16;

    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(windowSize.x, windowSize.y),
        "SFML works!",
        sf::Style::Default,
        settings
    );

    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);
}

void Scene::loadTextures() {
    std::string textureDirectory = "../resources/textures";
    loadTexturesToTextureManager(textureManager, textureDirectory);
}

void Scene::loadFonts() {
    sf::Font marrada;
    if (!marrada.loadFromFile("../resources/fonts/marrada.ttf")) {
        Logger::getInstance().log("Loading the main font 'marrada' failed!\n", LogLevel::Error);
        return;
    }

    fontManager.set(std::string("marrada"), marrada);
}

void Scene::loadDialogues() {
    dialogueManager = std::make_shared<DialogueManager>(
        *window,
        fontManager.get("marrada"),
        textureManager
    );

    dialogueManager->loadDialogues("../resources/dialogues");
}

void Scene::run() {
    
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        hero->handleMovement();
        hero->handlePickingUpItems(itemsOnMap);
        hero->handleChangingActiveItem();
        hero->handleStartingConversation(NPCs);
    
        for (auto& NPC: NPCs)
            NPC->selfManage(itemsOnMap, *hero);

        window->clear();
        
        for (auto& item: itemsOnMap)
            item->render(*window);

        for (auto& NPC: NPCs)
            NPC->render();

        hero->render();

        window->display();
    }
}
