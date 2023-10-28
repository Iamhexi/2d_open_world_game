#pragma once
#include <SFML/Graphics.hpp>
#include <map>

template<class T>
class ResourceManager
{
private:
    std::map<std::string, T> container;
public:
    T& get(std::string name);
    void set(std::string name, T resource);
};

std::vector<std::string> split(const std::string &s, char delimiter);

void loadTexturesToTextureManager
(
    ResourceManager<sf::Texture>& texturesManager,
    const std::string& textureDirectory
);

void loadTextureToTextureManager(
    ResourceManager<sf::Texture>& texturesManager,
    const std::string& textureName,
    const std::string& texturePath
);