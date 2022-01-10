#include "Item.hpp"
#include <vector>

class Inventory
{
private:
    // TODO: divide into two: graphics and logic of the Inventory
    sf::RenderWindow& window;
    sf::Sprite sprite;

    static constexpr unsigned int EMPTY_SLOT_ID = 0;
    static constexpr std::size_t inventorySize = 50;

    std::vector<Item> items;
    unsigned int currentItemIndex;

public:
    Inventory(sf::RenderWindow& window);
    bool addItem(Item item);
    bool removeItem(unsigned int id);
    Item& getCurrentItem();
    void next();
    void prev();

    void render() const;
private:
    unsigned int findFirstEmptySlot() const;
};
