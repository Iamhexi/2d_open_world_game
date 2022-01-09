#include "../include/Item.hpp"

unsigned int Item::uniqueId = 1;

void Item::assignId()
{
    this->id = Item::uniqueId++;
}

Item::Item(sf::Texture& texture)
    : texture(texture)
{

}

unsigned int Item::getId() const
{
    return id;
}

void Item::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
