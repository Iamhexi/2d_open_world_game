#include <SFML/Graphics.hpp>
#include "../include/ResourceManager.hpp"

template<class T>
T& ResourceManager<T>::get(std::string name)
{
    if (container.contains(name))
        return container[name];
    else
        throw std::string("Resource with the given name doesn't exits.");
}

template<class T>
void ResourceManager<T>::set(std::string name, T resource)
{
    if (container.contains(name))
        throw std::string("Resource with the given name already exits.");
    else
        container.emplace(std::pair{name, resource});
}

template class ResourceManager<sf::Font>;
template class ResourceManager<sf::Texture>;
