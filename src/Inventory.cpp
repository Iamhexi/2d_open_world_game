#include "../include/Inventory.hpp"
#include "../include/Logger.hpp"
#include <iostream>
#include <memory>
#include <algorithm>

std::shared_ptr<NotExistingItem> Inventory::notExistingItem = nullptr;

Inventory::Inventory(sf::RenderWindow& window, sf::Texture& notExistingItemTexture)
    : window(window)
{
    items.reserve(Inventory::maxInventorySize);
    currentItemIndex = 0;
    if (Inventory::notExistingItem == nullptr)
        Inventory::notExistingItem = std::make_shared<NotExistingItem>(notExistingItemTexture);
}


bool Inventory::addItem(Item item)
{
    if (items.size() > maxInventorySize)
        return false;

    items.push_back( std::make_shared<Item>(item) );
    return true;
}

bool Inventory::removeItem(unsigned int id)
{
    if (items.size() == 0)
        return false;
    
    if (currentItemIndex == items.size() - 1)
        currentItemIndex--;
    
    auto item = std::find_if(
        std::begin(items), std::end(items),
        [id](const std::shared_ptr<Item> item) -> bool { return item->getId() == id; });

    if (item == std::end(items)) {
        Logger::getInstance().log("An attempt to remove a non-existent item has occured.", LogLevel::Info);
        return false;
    }

    items.erase(item);
    return true;
}

std::shared_ptr<Item> Inventory::getCurrentItem()
{
    if (items.size() == 0) {
        Logger::getInstance().log("There was an attempt at retrieving an item from the empty inventory. The object of NotExistingItem was returned.", LogLevel::Warning);
        return Inventory::notExistingItem;
    }
    try {
        return items.at(currentItemIndex);
    } catch (const std::out_of_range& e) {
        Logger::getInstance().log("The currenty selected item's field is empty. The object of NotExistingItem was returned.", LogLevel::Warning);
        return Inventory::notExistingItem;
    }
}


void Inventory::next()
{
    if (items.size() == 0)
        return;

    else if (currentItemIndex + 1 < items.size())
        currentItemIndex++;
    else
        currentItemIndex = 0;
}

void Inventory::prev()
{
    if (items.size() == 0)
        return;

    else if (currentItemIndex - 1 > 0)
        currentItemIndex--;
    else
        currentItemIndex = items.size() - 1;
}

void Inventory::render() const
{
    window.draw(sprite);
    for (auto item: items)
        item->render(window);
}
