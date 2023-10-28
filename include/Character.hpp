#pragma once
#include <SFML/Graphics.hpp>
#include "Inventory.hpp"

class NPC;

class Character {
    friend NPC;

public:
    Character(sf::RenderWindow& window, sf::Texture& texture, sf::Vector2f startingPosition);
    virtual void handleMovement() = 0;
    virtual void handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap) = 0;
    virtual void handleChangingActiveItem() = 0;
    void render() const;
    virtual ~Character();

public:
    Inventory* inventory;
    static std::shared_ptr<sf::Texture> notExistingItemTexture;

protected:
    sf::RenderWindow& window;
    sf::Texture& texture;
    sf::Sprite sprite;
    sf::Sprite activeItemSprite;

    float speed = 3.5f;
    bool canMove = true;
    sf::Time minimumItemChangeThreshold = sf::milliseconds(150);
    sf::Clock itemChangeClock;

protected:
    virtual void moveUpIfPossible() = 0;
    virtual void moveDownIfPossible() = 0;
    virtual void moveRightIfPossible() = 0;
    virtual void moveLeftIfPossible() = 0;

    void moveSprites(float x, float y);
    void setUpSprites( sf::Vector2f startingPosition, sf::Texture& texture);
    bool enoughTimePassedSinceLastItemChange() const;
};
