#include "../include/Scene.hpp"

Scene::Scene(sf::Vector2i windowSize): windowSize(windowSize) {}

void Scene::init() {
    try {

    initWindow(); 
    loadFonts();
    loadTextures();

    Character::notExistingItemTexture = std::make_shared<sf::Texture>(textureManager.get("nonExistingItem"));
    
    std::string name = "Igor";
    Speaker igor( name, textureManager.get("hero") );
    igor.addDialogueLine("Hey, how are you?");
    igor.addDialogueLine("What are you doing?");

    std::string name2 = "Krzysztof";
    Speaker igor2( name2, textureManager.get("pig") );
    igor2.addDialogueLine("Well, I've been waiting for you...");
    igor2.addDialogueLine("Waiting?");

    Dialogue dialogue(*window, fontManager.get("marrada"));
    dialogue.addSpeaker(igor);
    dialogue.addSpeaker(igor2);


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
            std::make_shared<Dialogue>(dialogue)
        )
    );

    NPCs.emplace_back(
        std::make_shared<NPC>(
            *window,
            textureManager.get("farmer"),
            sf::Vector2f(500, 200),
            std::make_shared<Dialogue>(dialogue)
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
            NPC->selfManage(itemsOnMap);

        window->clear();
        
        for (auto& item: itemsOnMap)
            item->render(*window);

        for (auto& NPC: NPCs)
            NPC->render();

        hero->render();
        // dialogue.render();

        window->display();
    }
}
