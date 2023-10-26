#include "../include/Scene.hpp"

Scene::Scene(sf::Vector2i windowSize): windowSize(windowSize) {
    
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

void Scene::init() {
    initWindow(); // this function call has to be the first one

    std::string textureDirectory = "../resources/textures";
    loadTexturesToTextureManager(texturesManager, textureDirectory);


    sf::Font marrada;
    if (!marrada.loadFromFile("../resources/fonts/marrada.ttf"))
        std::cout << "Loading the marrada font failed!\n";

    fontsManager.set(std::string("marrada"), marrada);


    // std::string name = "Igor";
    // Speaker igor( name, texturesManager.get("hero") );
    // igor.addDialogueLine("Hey, how are you?");
    // igor.addDialogueLine("What are you doing?");

    // std::string name2 = "Krzysztof";
    // Speaker igor2( name2, texturesManager.get("pig") );
    // igor2.addDialogueLine("Well, I've been waiting for you...");
    // igor2.addDialogueLine("Waiting?");

    // Dialogue dialogue(window, fontsManager.get("marrada"));
    // dialogue.addSpeaker(igor);
    // dialogue.addSpeaker(igor2);
    // dialogue.start();

    // std::vector<std::shared_ptr<Item>> itemsOnMap;
    // auto axeLyingAround = std::make_shared<Item>(texturesManager.get("axe"));
    // itemsOnMap.push_back(axeLyingAround);


    hero = std::make_unique<Character>(
        *window,
        texturesManager.get("hero"),
        sf::Vector2f(500, 200),
        texturesManager.get("nonExistingItem")
    );

    
    Item axe(texturesManager.get("axe"));
    hero->inventory->addItem(axe);

    Logger::getInstance().printEventLog(LogLevel::Info);
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
        // hero->handleStartingDialogue(charactersOnMap);
        // dialogue.handle();

        window->clear();
        
        for (auto& item: itemsOnMap)
            item->render(*window);

        hero->render();
        // dialogue.render();

        window->display();
    }
}
