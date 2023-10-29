#include "../include/NPC.hpp"
#include <iostream>

NPC::NPC(
    sf::RenderWindow& window,
    sf::Texture& texture,
    sf::Vector2f startingPosition,
    Dialogue& dialogue
): Character(window, texture, startingPosition), dialogue(dialogue) {
    path = std::make_shared<Path>(window);
    path->generateRandomPath(10);
}

void NPC::selfManage(std::vector<std::shared_ptr<Item>>& itemsOnMap, Player& player) {
    handleMovement();
    handleDialogues(player);
    handlePickingUpItems(itemsOnMap);
    handleChangingActiveItem();
}

void NPC::startDialogue() {
    dialogue.start();
    dialogueStarted = true;
}

void NPC::handleDialogues(Player& player) {
    if (dialogueStarted) {
        dialogue.handle();
        if (dialogue.isFinished())
            player.finishConversation();
    }
    
}

void NPC::handleMovement() {
    if (!canMove)
        return;

    if (reachedDestination())
        path->markDestinationAsCompleted( path->getCurrentDestination() );

    moveTowards( path->getCurrentDestination() );
}

void NPC::handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap)  {
    
}

void NPC::handleChangingActiveItem()  {
    
}

void NPC::moveUpIfPossible() {
    if (sprite.getPosition().y - speed >= 0) 
        moveSprites(0, -speed);
}

void NPC::moveDownIfPossible() {
    if (sprite.getPosition().y + speed <= window.getSize().y - 540) // TODO: make space for a panel with inventory
        moveSprites(0, speed);
}

void NPC::moveRightIfPossible() {
    if (sprite.getPosition().x - speed >= 0)
        moveSprites(-speed, 0);
}

void NPC::moveLeftIfPossible() {
    if (sprite.getPosition().x + texture.getSize().x + speed <= window.getSize().x)
        moveSprites(speed, 0);
}

bool NPC::reachedDestination() const {
    return std::abs(sprite.getPosition().x - path->getCurrentDestination().x) < speed &&
           std::abs(sprite.getPosition().y - path->getCurrentDestination().y) < speed;
}

void NPC::moveTowards(const sf::Vector2f& destination) {

    if ( std::abs(sprite.getPosition().x - path->getCurrentDestination().x) >= speed ) {

        if (sprite.getPosition().x < destination.x)
            moveLeftIfPossible();
        else if (sprite.getPosition().x > destination.x)
            moveRightIfPossible();

    }
    
    if ( std::abs(sprite.getPosition().y - path->getCurrentDestination().y) >= speed ) {

        if (sprite.getPosition().y < destination.y)
            moveDownIfPossible();
        else if (sprite.getPosition().y > destination.y)
            moveUpIfPossible();

    }
}

void NPC::render() const {
    Character::render();
    dialogue.render();
}
