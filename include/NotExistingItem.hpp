#include "Item.hpp"

#ifndef NOT_EXISTING_ITEM_HPP
#define NOT_EXISTING_ITEM_HPP

class NotExistingItem : public Item
{
public:
    NotExistingItem(sf::Texture& texture);
    unsigned int getId() const;
};

#endif
