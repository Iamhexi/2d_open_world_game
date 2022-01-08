#include "../include/Item.hpp"

unsigned int Item::uniqueId = 1;

void Item::assignId()
{
    this->id = Item::uniqueId++;
}

Item::Item()
{
    id = 0;
}

unsigned int Item::getId() const
{
    return id;
}
