#include "../include/NotExistingItem.hpp"

NotExistingItem::NotExistingItem(sf::Texture& texture)
    : Item(texture)
{

}

unsigned int NotExistingItem::getId() const
{
    return -1;
}
