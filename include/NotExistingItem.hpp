#pragma once
#include "Item.hpp"

class NotExistingItem : public Item
{
public:
    NotExistingItem(sf::Texture& texture);
    unsigned int getId() const;
};

