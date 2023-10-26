#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/ResourceManager.hpp"
#include "../include/Logger.hpp"
#include <filesystem>
#include <sstream>

template<class T>
T& ResourceManager<T>::get(std::string name)
{
    if (container.contains(name))
        return container[name];
    else
    {
      std::string errorMessage = "Resource with the name '" + name + "' doesn't exits so cannot be acquired.";
      Logger::getInstance().log(errorMessage, LogLevel::Error);
      throw std::string(errorMessage);
    }
}

template<class T>
void ResourceManager<T>::set(std::string name, T resource)
{
    if (container.contains(name))
      Logger::getInstance().log("Resource with the name = '" + name  + "' already exits, thus cannot be created.", LogLevel::Warning);
    else
        container.emplace(std::pair{name, resource});
}

template class ResourceManager<sf::Font>;
template class ResourceManager<sf::Texture>;
template class ResourceManager<sf::SoundBuffer>;



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