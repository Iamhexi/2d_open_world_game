#include "../include/ToolItemFactory.hpp"

Item ToolItemFactory::createItem(sf::Texture& texture)
{
    ToolItem item(texture);
    return item;
}
