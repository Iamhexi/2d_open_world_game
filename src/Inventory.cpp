#include "../include/Inventory.hpp"
#include "../include/NotExistingItemFactory.hpp"
#include "../include/Logger.hpp"
#include <iostream>

Inventory::Inventory(sf::RenderWindow& window, sf::Texture& notExistingItemTexture)
    : window(window)
{
    //NotExistingItemFactory factory;
    //notExistingItem = std::make_unique<NotExistingItem>( factory.createItem(notExistingItemTexture) );

    items.reserve(Inventory::maxInventorySize);
    currentItemIndex = 0;
}


bool Inventory::addItem(Item item)
{
    if (items.size() > maxInventorySize)
        return false;

    items.push_back(item);
}

bool Inventory::removeItem(unsigned int id)
{
    if (items.size() == 0)
        return false;
 // TODO: create a method removing an item from the inventory
}

Item& Inventory::getCurrentItem()
{
    try {
        return items.at(0);
    } catch (const std::out_of_range& e) {
        // TODO: return NotExistingItem Object called Null Object
        //return *(Inventory::notExistingItem);
        Logger::getInstance().log("There was an attempt at retrieving an item from the empty inventory. The object of NotExistingItem was returned.", LogLevel::Warning);
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
    for (Item item: items)
        item.render(window);
}
