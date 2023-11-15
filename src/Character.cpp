#include "../include/Character.hpp"
#include <iostream>

std::shared_ptr<sf::Texture> Character::notExistingItemTexture = nullptr;

Character::Character(
    sf::RenderWindow& window,
    sf::Texture& texture,
    sf::Vector2f startingPosition
): window(window), texture(texture)
{
    inventory = new Inventory(window, *(Character::notExistingItemTexture));

    setUpSprites(startingPosition, texture);

    itemChangeClock.restart();
}

void Character::takeDamage(float damage) {
    living.takeDamage(damage);
}

void Character::setUpSprites( sf::Vector2f startingPosition, sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(startingPosition);

    activeItemSprite.setTexture( inventory->getCurrentItem()->texture );
    activeItemSprite.setPosition( 
        sprite.getGlobalBounds().left + sprite.getGlobalBounds().width,
        sprite.getGlobalBounds().top
    );
    activeItemSprite.setScale(0.5f, 0.5f);
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
                if (inventory->addItem(*itemsOnMap[i])) {
                    itemsOnMap.erase( itemsOnMap.begin() + i );
                    return ;
                }
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
    
    activeItemSprite.setTexture( inventory->getCurrentItem()->texture );

    itemChangeClock.restart();
}

bool Character::enoughTimePassedSinceLastItemChange() const {
    return itemChangeClock.getElapsedTime() >= minimumItemChangeThreshold;
}

void Character::render() const
{

    window.draw(sprite);
    window.draw(activeItemSprite);

    inventory->render();
}

void Character::moveSprites(float x, float y) {
    sprite.move(x, y);
    activeItemSprite.move(x, y);
}

void Character::moveUpIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        if (sprite.getPosition().y - speed >= 0) 
            moveSprites(0, -speed);
}

void Character::moveDownIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        if (sprite.getPosition().y + speed <= window.getSize().y - 540) // TODO: make space for a panel with inventory
            moveSprites(0, speed);
}

void Character::moveRightIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        if (sprite.getPosition().x - speed >= 0)
            moveSprites(-speed, 0);
}

void Character::moveLeftIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        if (sprite.getPosition().x + texture.getSize().x + speed <= window.getSize().x)
            moveSprites(speed, 0);
}

Character::~Character() {
    delete inventory;
}

std::vector<std::shared_ptr<Character>> Character::findNearbyCharacters(std::shared_ptr<Character> player, std::vector<std::shared_ptr<Character>> otherNPCs) const {
    
    // TODO: remove this NPC object from otherNPCs vector
    std::vector<std::shared_ptr<Character>> nearbyCharacters;
    if (player->sprite.getGlobalBounds().intersects( sprite.getGlobalBounds() ))
        nearbyCharacters.push_back(player);

    for (auto npc: otherNPCs)
        // if (npc == std::make_shared<Character>(this))
        //     break;
        if (npc->sprite.getGlobalBounds().intersects( sprite.getGlobalBounds() ))
            nearbyCharacters.push_back(npc);
    
    return nearbyCharacters;

}