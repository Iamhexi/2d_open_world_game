#include "../include/NPC.hpp"
#include <iostream>

NPC::NPC(
    sf::RenderWindow& window,
    sf::Texture& texture,
    sf::Vector2f startingPosition,
    std::shared_ptr<Dialogue> dialogue
): Character(window, texture, startingPosition) {
    this->dialogue = dialogue;
}

void NPC::selfManage(std::vector<std::shared_ptr<Item>>& itemsOnMap) {
    handleMovement();
    handleDialogues();
    handlePickingUpItems(itemsOnMap);
    handleChangingActiveItem();
}

void NPC::startDialogue() {
    dialogue->start();
    dialogueStarted = true;
    std::cout << "Dialogue started!\n";
}

void NPC::handleDialogues() {
    if (dialogueStarted)
        dialogue->handle();
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
    dialogue->render();
}
