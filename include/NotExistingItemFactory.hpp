#pragma once
#include "NotExistingItem.hpp"
#include "ItemFactory.hpp"

class NotExistingItemFactory : public ItemFactory
{
public:
    Item createItem(sf::Texture& texture) override;
};
