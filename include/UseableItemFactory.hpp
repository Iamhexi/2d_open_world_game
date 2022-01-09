#pragma once
#include "ItemFactory.hpp"

class UseableItemFactory : public ItemFactory
{
    Item createItem(sf::Texture& texture) override;
};
