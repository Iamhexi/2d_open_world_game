#pragma once
#include "Component.hpp"

class InventoryComponent : public Component {

public:
    InventoryComponent(sf::RenderWindow& window, sf::Texture& notExistingItemTexture);
    
    virtual bool intersects(ComponentPtr other) const;
    virtual void move(const sf::Vector2f& movement);

    void drawItemSlot(sf::Vector2f initalPosition, sf::Vector2f size, bool isActive) const;

private:
    sf::RenderWindow& window;
    sf::Texture& notExistingItemTexture;

    static constexpr float slotSide = 55.f;
};