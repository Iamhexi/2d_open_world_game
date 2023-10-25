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
    sf::Sprite sprite;

    std::vector<std::shared_ptr<Item>> items;
    unsigned int currentItemIndex;

    static constexpr unsigned int emptySlotId = 0;


    static constexpr std::size_t maxInventorySize = 50;
    static std::shared_ptr<NotExistingItem> notExistingItem;

private:
};
