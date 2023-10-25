#include "../include/Item.hpp"

unsigned int Item::uniqueId = 1;

Item::Item(sf::Texture& texture)
    : texture(texture)
{
    this->id = Item::uniqueId++;
}

unsigned int Item::getId() const
{
    return id;
}

void Item::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
