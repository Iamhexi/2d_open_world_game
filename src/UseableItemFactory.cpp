#include "../include/UseableItemFactory.hpp"
#include "../include/UseableItem.hpp"

Item UseableItemFactory::createItem(sf::Texture& texture)
{
    UseableItem item(texture);
    return item;
}
