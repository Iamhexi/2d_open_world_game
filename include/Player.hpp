#pragma once
#include <SFML/Graphics.hpp>
#include "Character.hpp"

class NPC;

class Player : public Character{
    friend NPC;

public:
    Player(sf::RenderWindow& window, sf::Texture& texture, sf::Vector2f startingPosition);
    virtual void handleMovement() override;
    virtual void handlePickingUpItems(std::vector<std::shared_ptr<Item>>& itemsOnMap) override;
    virtual void handleChangingActiveItem() override;
    void handleStartingConversation(std::vector<std::shared_ptr<NPC>> NPCs);
    void finishConversation();

protected:
    virtual void moveUpIfPossible() override;
    virtual void moveDownIfPossible() override;
    virtual void moveRightIfPossible() override;
    virtual void moveLeftIfPossible() override;

private:
    bool inConversation {false};
};
