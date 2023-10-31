#include "../include/Player.hpp"
#include "../include/NPC.hpp"
#include <iostream>

using ItemPtr = std::shared_ptr<Item>;

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



void Player::handlePickingUpItems(std::vector<ItemPtr>& itemsOnMap) {
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
        return;

    const size_t size = itemsOnMap.size();
    for (size_t i = 0; i < size; i++) {
        if ( canPickUpItem( *(itemsOnMap[i]) ) ) {
            itemsOnMap.erase( itemsOnMap.begin() + i );
            return ;
        }
    }

}

bool Player::canPickUpItem(const Item& item) const {
    if (sprite.getGlobalBounds().intersects( item.sprite.getGlobalBounds() ))
        if (inventory->addItem(item))
            return true;
    return false;
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

void Player::handleStartingConversation(std::vector<std::shared_ptr<Character>> NPCs) {
    if (inConversation)
        return ;
    if ( !sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Z ) )
        return ;
    
    for ( auto& npc: NPCs ) {
        auto nearbyNPC = static_pointer_cast<NPC>( npc );
        if ( nearbyNPC->sprite.getGlobalBounds().intersects( sprite.getGlobalBounds() ) ) {
            nearbyNPC->startDialogue();
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

void Player::handleFight(std::shared_ptr<Character> player, std::vector<std::shared_ptr<Character>> otherNPCs) {
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        return;
    
    auto nearbyCharacters = findNearbyCharacters(player, otherNPCs);
    attackClock.restart();
    
    // TODO: prevent constant attacks by introducing block time
    if (isEligibleToAttack(nearbyCharacters)) {
        
        startAttackAnimation();
        for (auto character: nearbyCharacters)
            character->takeDamage(damage);

    }


}

void Player::startAttackAnimation() {
    activeItemSprite.rotate(90);
}