#include "../include/NotExistingItem.hpp"

NotExistingItem::NotExistingItem(sf::Texture& texture, sf::FloatRect spawnArea)
    : Item(texture, spawnArea)
{

}

unsigned int NotExistingItem::getId() const
{
    return -1;
}
