#include "../include/NotExistingItemFactory.hpp"

Item NotExistingItemFactory::createItem(sf::Texture& texture)
{
    NotExistingItem item(texture);
    return item;
}
