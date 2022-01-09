#pragma once
#include "Item.hpp"

class ItemFactory
{
public:
    virtual Item createItem(sf::Texture& texture) = 0;
};
