#pragma once
#include "NotExistingItem.hpp"
#include <memory>
#include <vector>

class Inventory
{
public:
    Inventory(sf::RenderWindow& window, sf::Texture& notExistingItemTexture);
    bool addItem(Item item);
    bool removeItem(unsigned int id);
    std::shared_ptr<Item> getCurrentItem();
    void next();
    void prev();
    void render() const;

private:
    // TODO: divide into two: graphics and logic of the Inventory
    sf::RenderWindow& window;

    std::vector<std::shared_ptr<Item>> items;
    unsigned int currentItemIndex;

    static constexpr unsigned int emptySlotId = 0;


    static constexpr std::size_t maxInventorySize = 15;
    static std::shared_ptr<NotExistingItem> notExistingItem;

    static constexpr float slotSide = 55.f;

private:
    void drawItemSlot(sf::Vector2f initalPosition, sf::Vector2f size, bool isActive) const;
};
