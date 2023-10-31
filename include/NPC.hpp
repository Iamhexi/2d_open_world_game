#pragma once
#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Dialogue.hpp"
#include "Player.hpp"
#include "Path.hpp"
using ItemPtr = std::shared_ptr<Item>;

class NPC : public Character {
    friend Player;
    friend Character;

public:
    NPC(
        sf::RenderWindow& window,
        sf::Texture& texture,
        sf::Vector2f startingPosition,
        Dialogue& dialogue
    );

    void selfManage(
        std::vector<std::shared_ptr<Character>>& NPCsOnMap,
        std::vector<ItemPtr>& itemsOnMap,
        std::shared_ptr<Player> player
    );


    void startDialogue();

    void render() const;

private:
    void handleDialogues(Player& player);
    virtual void handleMovement() override;
    virtual void handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap) override;
    virtual void handleChangingActiveItem() override;
    virtual void handleFight(std::shared_ptr<Character> player, std::vector<std::shared_ptr<Character>> otherNPCs) override;
    
    virtual void moveUpIfPossible() override;
    virtual void moveDownIfPossible() override;
    virtual void moveRightIfPossible() override;
    virtual void moveLeftIfPossible() override;

    void moveTowards(const sf::Vector2f& destination);
    bool reachedDestination() const;
    void startAttackAnimation();

private:
    bool dialogueStarted {false};
    Dialogue& dialogue;
    std::shared_ptr<Path> path;
};