#include "../include/NPC.hpp"
#include <iostream>

using ItemPtr = std::shared_ptr<Item>;

NPC::NPC(
    sf::RenderWindow& window,
    sf::Texture& texture,
    sf::Vector2f startingPosition,
    Dialogue& dialogue
): Character(window, texture, startingPosition), dialogue(dialogue) {
    path = std::make_shared<Path>(window);
    path->generateRandomPath(10);
    breakBetweenAttacks = sf::milliseconds(1000);
}

void NPC::selfManage(
    std::vector<std::shared_ptr<Character>>& NPCsOnMap,
    std::vector<ItemPtr>& itemsOnMap,
    std::shared_ptr<Player> player
) {
    handleMovement();
    handleDialogues(*player);
    handlePickingUpItems(itemsOnMap);
    handleChangingActiveItem();
    handleFight(player, NPCsOnMap);
}

void NPC::startDialogue() {
    dialogue.start();
    dialogueStarted = true;
}

void NPC::handleDialogues(Player& player) {
    if (dialogueStarted) {
        dialogue.handle();
        if (dialogue.isFinished()) {
            player.finishConversation();
            dialogueStarted = false;
        }
    }
    
}

void NPC::handleMovement() {
    if (!canMove || dialogueStarted)
        return;

    if (reachedDestination())
        path->markDestinationAsCompleted( path->getCurrentDestination() );

    moveTowards( path->getCurrentDestination() );
}

void NPC::handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap)  {
    
}

void NPC::handleChangingActiveItem()  {
    
}

void NPC::startAttackAnimation() {
    activeItemSprite.rotate(10);
    attackClock.restart();
}

void NPC::handleFight(std::shared_ptr<Character> player, std::vector<std::shared_ptr<Character>> otherNPCs) {
    auto nearbyCharacters = findNearbyCharacters(player, otherNPCs);

    if (isEligibleToAttack(nearbyCharacters))
        startAttackAnimation();
        

    // TODO: After making an attack, introduce inability time during which attacks don't occur. Prevent constant attack attacks.

    // for (auto character: nearbyCharacters)
        // character->takeDamage(damage);
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
    if (health > 0) {
        dialogue.render();
        Character::render();
    }
}
