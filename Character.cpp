#include "Character.hpp"


Character::Character(
    sf::RenderWindow& window,
    sf::Texture& texture,
    sf::Vector2f startingPosition
): window(window), texture(texture)
{
    sprite.setTexture(texture);
    sprite.setPosition(startingPosition);
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

void Character::render()
{
    window.draw(sprite);
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
        if (sprite.getPosition().y + speed <= window.getSize().y)
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
        if (sprite.getPosition().x + speed <= window.getSize().x)
            sprite.move(speed, 0);
}
