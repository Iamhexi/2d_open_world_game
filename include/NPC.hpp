#pragma once
#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Dialogue.hpp"

class Player;

class NPC : public Character {
    friend Player;

public:
    NPC(
        sf::RenderWindow& window,
        sf::Texture& texture,
        sf::Vector2f startingPosition,
        std::shared_ptr<Dialogue> dialogue
    );

    void selfManage(std::vector<std::shared_ptr<Item>>& itemsOnMap);
    void startDialogue();

    void render() const;

private:
    void handleDialogues();
    virtual void handleMovement() override;
    virtual void handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap) override;
    virtual void handleChangingActiveItem() override;
    
    virtual void moveUpIfPossible() override;
    virtual void moveDownIfPossible() override;
    virtual void moveRightIfPossible() override;
    virtual void moveLeftIfPossible() override;

private:
    bool dialogueStarted {false};
    std::shared_ptr<Dialogue> dialogue;
};