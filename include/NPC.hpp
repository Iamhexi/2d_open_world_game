#pragma once
#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Dialogue.hpp"
#include "Player.hpp"

class NPC : public Character {
    friend Player;

public:
    NPC(
        sf::RenderWindow& window,
        sf::Texture& texture,
        sf::Vector2f startingPosition,
        Dialogue& dialogue
    );

    void selfManage(std::vector<std::shared_ptr<Item>>& itemsOnMap, Player& player);
    void startDialogue();

    void render() const;

private:
    void handleDialogues(Player& player);
    virtual void handleMovement() override;
    virtual void handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap) override;
    virtual void handleChangingActiveItem() override;
    
    virtual void moveUpIfPossible() override;
    virtual void moveDownIfPossible() override;
    virtual void moveRightIfPossible() override;
    virtual void moveLeftIfPossible() override;

private:
    bool dialogueStarted {false};
    Dialogue& dialogue;
};