#include "../include/Inventory.hpp"
#include <iostream>

Inventory::Inventory(sf::RenderWindow& window)
    : window(window)
{
    items.reserve(Inventory::inventorySize);
    currentItemIndex = 0;
}


bool Inventory::addItem(Item item)
{
    // TODO: Fix erro by adding operator=
    // note: ‘Item& Item::operator=(const Item&)’ is implicitly deleted because the default definition would be ill-formed

    //items.at( findFirstEmptySlot() ) = item;
    //firstEmptyInventorySlotIndex++;

}

bool Inventory::removeItem(unsigned int id)
{
 // TODO: create a method removing an item from the inventory
}

Item& Inventory::getCurrentItem()
{
    // try {
        // return this->items.at(currentItemIndex);
    // } catch (std::out_of_range e){
        // std::cout << e.what() << ": The inner inventory's indicator points outside of the inventory. Any returned reference is invalid.\n";
    // }
}


void Inventory::next()
{
    if (currentItemIndex + 1 < inventorySize)
        currentItemIndex++;
    else
        currentItemIndex = 0;
}

void Inventory::prev()
{
    if (currentItemIndex - 1 > 0)
        currentItemIndex--;
    else
        currentItemIndex = inventorySize - 1;
}

void Inventory::render() const
{
    window.draw(sprite);
    for (Item item: items)
        item.render(window);
}

unsigned int Inventory::findFirstEmptySlot() const
{
    /*
    for (std::size_t i = 0; Item item: items)
    {
        if ( item.getId() == EMPTY_SLOT_ID )
            return i;
        i++;
    }
    */
}
//
