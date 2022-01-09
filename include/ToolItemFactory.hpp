#pragma once
#include "ToolItem.hpp"
#include "ItemFactory.hpp"

class ToolItemFactory : public ItemFactory
{
public:
    Item createItem(sf::Texture& texture) override;
};
