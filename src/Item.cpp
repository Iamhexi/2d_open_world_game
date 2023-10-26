#include "../include/Item.hpp"

unsigned int Item::uniqueId = 1;

Item::Item(sf::Texture& texture)
    : texture(texture)
{
    sprite.setTexture(texture);

    this->id = Item::uniqueId++;
    
    sprite.setPosition(10.f*id, 20.f*id);
}

unsigned int Item::getId() const
{
    return id;
}

void Item::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
