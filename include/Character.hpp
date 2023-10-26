#pragma once
#include <SFML/Graphics.hpp>
#include "Inventory.hpp"

class Character
{
private:
    sf::RenderWindow& window;
    sf::Texture& texture;
    sf::Sprite sprite;
    float speed = 3.5f;
    bool canMove = true;
public:
    Character(sf::RenderWindow& window, sf::Texture& texture, sf::Vector2f startingPosition, sf::Texture& notExistingItemTexture);
    void handleMovement();
    void render() const;
    virtual ~Character();
    Inventory* inventory;
private:
    void moveUpIfPossible();
    void moveDownIfPossible();
    void moveRightIfPossible();
    void moveLeftIfPossible();
};
