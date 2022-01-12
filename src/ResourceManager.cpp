#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/ResourceManager.hpp"
#include "../include/Logger.hpp"

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
