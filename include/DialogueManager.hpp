#pragma once
#include <SFML/Graphics.hpp>
#include "Dialogue.hpp"
#include "ResourceManager.hpp"
#include "Logger.hpp"


class DialogueManager {

public:
    DialogueManager(
        sf::RenderWindow& window,
        sf::Font& font,
        ResourceManager<sf::Texture>& textureManager
    );
    void loadDialogues(const std::string& dialogueDirectoryPath);
    Dialogue& get(const std::string& NPCName);
    
private:
    static std::shared_ptr<Dialogue> emptyDialogue;

private:
    void loadDialogue(const std::string& path, const std::string& filename);

private:
    std::map<std::string, Dialogue> dialogues;
    sf::RenderWindow& window;
    sf::Font& font;
    ResourceManager<sf::Texture>& textureManager;

};