#include "NotExistingItem.hpp"
#include <vector>

class Inventory
{
public:
    Inventory(sf::RenderWindow& window, sf::Texture& notExistingItemTexture);
    bool addItem(Item item);
    bool removeItem(unsigned int id);
    Item& getCurrentItem();
    void next();
    void prev();
    void render() const;

private:
    // TODO: divide into two: graphics and logic of the Inventory
    sf::RenderWindow& window;
    sf::Sprite sprite;

    std::vector<Item> items;
    unsigned int currentItemIndex;

    static constexpr unsigned int emptySlotId = 0;


    static constexpr std::size_t maxInventorySize = 50;
    //static std::unique_ptr<NotExistingItem> notExistingItem;

private:
};
