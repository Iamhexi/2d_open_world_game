#include "../include/Player.hpp"
#include "../include/NPC.hpp"
#include <iostream>

Player::Player(
    sf::RenderWindow& window,
    sf::Texture& texture,
    sf::Vector2f startingPosition
) : Character(window, texture, startingPosition) {

}

void Player::handleMovement()
{
    if (canMove && !inConversation) {
        moveUpIfPossible();
        moveDownIfPossible();
        moveRightIfPossible();
        moveLeftIfPossible();
    }
}

void Player::handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap) {
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

void Player::handleChangingActiveItem() {
    
    if (!enoughTimePassedSinceLastItemChange())
        return ;

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::E ))
        inventory->next();
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Q ))
        inventory->prev();
    
    activeItemSprite.setTexture( inventory->getCurrentItem()->texture );

    itemChangeClock.restart();
}

void Player::finishConversation() {
    inConversation = false;
}

void Player::handleStartingConversation(std::vector<std::shared_ptr<NPC>> NPCs) {
    if (inConversation)
        return ;
    if ( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Z ) )
        return ;
    
    for ( auto& npc: NPCs ) {
        if ( npc->sprite.getGlobalBounds().intersects( sprite.getGlobalBounds() ) ) {
            npc->startDialogue();
            inConversation = true;
            return;
        }

    }
}

void Player::moveUpIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        if (sprite.getPosition().y - speed >= 0) 
            moveSprites(0, -speed);
}

void Player::moveDownIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        if (sprite.getPosition().y + speed <= window.getSize().y - 540) // TODO: make space for a panel with inventory
            moveSprites(0, speed);
}

void Player::moveRightIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        if (sprite.getPosition().x - speed >= 0)
            moveSprites(-speed, 0);
}

void Player::moveLeftIfPossible()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        if (sprite.getPosition().x + texture.getSize().x + speed <= window.getSize().x)
            moveSprites(speed, 0);
}