#pragma once
#include "Item.hpp"

class NotExistingItem : public Item
{
public:
    NotExistingItem(sf::Texture& texture, sf::FloatRect spawnArea);
    unsigned int getId() const;
};

