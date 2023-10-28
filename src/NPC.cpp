#include "../include/NPC.hpp"
#include <iostream>

NPC::NPC(
    sf::RenderWindow& window,
    sf::Texture& texture,
    sf::Vector2f startingPosition,
    Dialogue& dialogue
): Character(window, texture, startingPosition), dialogue(dialogue) {

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

void NPC::handleMovement()  {

}

void NPC::handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap)  {
    
}

void NPC::handleChangingActiveItem()  {
    
}

void NPC::moveUpIfPossible() {

}

void NPC::moveDownIfPossible() {

}

void NPC::moveRightIfPossible() {

}

void NPC::moveLeftIfPossible() {

}

void NPC::render() const {
    Character::render();
    dialogue.render();
}
