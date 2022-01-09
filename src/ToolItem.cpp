#include "../include/ToolItem.hpp"

ToolItem::ToolItem(sf::Texture& texture)
    : Item(texture)
{
    assignId();
}
