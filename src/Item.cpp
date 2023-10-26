#include "../include/Item.hpp"

unsigned int Item::uniqueId = 1;

Item::Item(sf::Texture& texture, sf::FloatRect spawnArea)
    : texture(texture)
{
    sprite.setTexture(texture);
    this->id = Item::uniqueId++;
    randomizePosition(spawnArea);
}

unsigned int Item::getId() const {
    return id;
}

void Item::render(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Item::randomizePosition(sf::FloatRect spawnArea) {
    sprite.setPosition( 
        RandomNumberGenerator::generate(spawnArea.left, spawnArea.left + spawnArea.width),
        RandomNumberGenerator::generate(spawnArea.top, spawnArea.top - spawnArea.height)
    );
}