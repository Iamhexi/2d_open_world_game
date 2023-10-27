#pragma once
#include <SFML/Graphics.hpp>
#include "Inventory.hpp"

class Character
{

public:
    Character(sf::RenderWindow& window, sf::Texture& texture, sf::Vector2f startingPosition, sf::Texture& notExistingItemTexture);
    void handleMovement();
    void handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap);
    void handleChangingActiveItem();
    void render() const;
    virtual ~Character();
    Inventory* inventory;

private:
    sf::RenderWindow& window;
    sf::Texture& texture;
    sf::Sprite sprite;

    sf::Sprite activeItemSprite;

    float speed = 3.5f;
    bool canMove = true;
    sf::Time minimumItemChangeThreshold = sf::milliseconds(150);
    sf::Clock itemChangeClock;

private:
    void moveUpIfPossible();
    void moveDownIfPossible();
    void moveRightIfPossible();
    void moveLeftIfPossible();

    bool enoughTimePassedSinceLastItemChange() const;
    void moveSprites(float x, float y);
    void setUpSprites( sf::Vector2f startingPosition, sf::Texture& texture);
};
