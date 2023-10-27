#include "../include/Character.hpp"
#include <iostream>

Character::Character(
    sf::RenderWindow& window,
    sf::Texture& texture,
    sf::Vector2f startingPosition,
    sf::Texture& notExistingItemTexture
): window(window), texture(texture)
{
    inventory = new Inventory(window, notExistingItemTexture);
    sprite.setTexture(texture);
    sprite.setPosition(startingPosition);
    itemChangeClock.restart();
}

void Character::handleMovement()
{
    if (canMove)
    {
        moveUpIfPossible();
        moveDownIfPossible();
        moveRightIfPossible();
        moveLeftIfPossible();
    }
}

void Character::handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap) {
    const size_t size = itemsOnMap.size();
    for (size_t i = 0; i < size; i++) {
        if (sprite.getGlobalBounds().intersects( itemsOnMap[i]->sprite.getGlobalBounds() ) ) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
                inventory->addItem(*itemsOnMap[i]);
                itemsOnMap.erase( itemsOnMap.begin() + i );
                return ;
            }

        }
    }
}

void Character::handleChangingActiveItem() {
    
    if (!enoughTimePassedSinceLastItemChange())
        return ;

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::E ))
        inventory->next();
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Q ))
        inventory->prev();
    
    itemChangeClock.restart();
}

bool Character::enoughTimePassedSinceLastItemChange() const {
    return itemChangeClock.getElapsedTime() >= minimumItemChangeThreshold;
}

void Character::render() const
{
    window.draw(sprite);
    inventory->render();
}

void Character::moveUpIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        if (sprite.getPosition().y - speed >= 0)
            sprite.move(0, -speed);
}

void Character::moveDownIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        if (sprite.getPosition().y + speed <= window.getSize().y - 540) // TODO: make space for a panel with inventory
            sprite.move(0, speed);
}

void Character::moveRightIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        if (sprite.getPosition().x - speed >= 0)
            sprite.move(-speed, 0);
}

void Character::moveLeftIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        if (sprite.getPosition().x + texture.getSize().x + speed <= window.getSize().x)
            sprite.move(speed, 0);
}

Character::~Character() {
    delete inventory;
}
