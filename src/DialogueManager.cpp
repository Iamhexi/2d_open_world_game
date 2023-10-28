#include "../include/DialogueManager.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <tuple>
namespace fs = std::filesystem;

std::shared_ptr<Dialogue> DialogueManager::emptyDialogue;

DialogueManager::DialogueManager(
    sf::RenderWindow& window,
    sf::Font& font,
    ResourceManager<sf::Texture>& textureManager
): window(window), font(font), textureManager(textureManager) {
    emptyDialogue = std::make_shared<Dialogue>(window, font);
}

void DialogueManager::loadDialogues(const std::string& dialogueDirectoryPath) {
    const fs::path pathToShow {dialogueDirectoryPath};

    for (const auto& entry : fs::directory_iterator(pathToShow)) {
        const auto filename = entry.path().filename().string();
        std::string texturePath = dialogueDirectoryPath + '/' + filename;
        loadDialogue(texturePath, filename);
    }
}

Dialogue& DialogueManager::get(const std::string& NPCName) {
    if (dialogues.contains(NPCName))
        return dialogues.at(NPCName);
    Logger::getInstance().log(std::string("An attempt was made to get the non-existent dialogue for ") + NPCName, LogLevel::Error);
}

void DialogueManager::loadDialogue(const std::string& path, const std::string& filename) {
    std::ifstream file(path.c_str());
    std::string speaker = split(filename, '.').at(0);


    if (!file.is_open()) {
        Logger::getInstance().log(
            std::string("Couldn't load a the dialogue from the file ") + filename 
            + ". Any attempt to get this dialogue will result in receiving nullptr causing potential crash.",
            LogLevel::Warning
        );
        return ;
    }
    
    auto result = dialogues.try_emplace(
        speaker, window, font
    );

    if (!result.second) {
        file.close();
        Logger::getInstance().log("Failed to insert the loaded dialogue to Dialogue Manager.", LogLevel::Warning);
        return;
    }


    Speaker player("You", textureManager.get("hero"));
    Speaker npc(speaker, textureManager.get(speaker));

    std::string playerLine, NPCLine;
    while (std::getline(file, playerLine) && std::getline(file, NPCLine)) {
        player.addDialogueLine(playerLine);
        npc.addDialogueLine(NPCLine);
    }

    dialogues.at(speaker).addSpeaker(player);
    dialogues.at(speaker).addSpeaker(npc);
    
    file.close();
}
