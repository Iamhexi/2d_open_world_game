#include "../include/Inventory.hpp"
#include "../include/Logger.hpp"
#include <iostream>
#include <memory>
#include <algorithm>

std::shared_ptr<NotExistingItem> Inventory::notExistingItem = nullptr;

Inventory::Inventory(sf::RenderWindow& window, sf::Texture& notExistingItemTexture)
    : window(window)
{
    currentItemIndex = 0;
    if (Inventory::notExistingItem == nullptr)
        Inventory::notExistingItem = std::make_shared<NotExistingItem>(notExistingItemTexture, sf::FloatRect());
}

bool Inventory::addItem(Item item)
{
    if (items.size() > maxInventorySize)
        return false;

    items.push_back( std::make_shared<Item>(item) );
    auto& lastItem = items.at( items.size() - 1 );

    const float scaleFactor = slotSide /  (lastItem->sprite.getTexture()->getSize().x * lastItem->sprite.getScale().x);
    lastItem->sprite.scale(scaleFactor, scaleFactor); 
    return true;
}

bool Inventory::removeItem(unsigned int id)
{
    if (items.size() == 0)
        return false;
    
    if ( static_cast<size_t>(currentItemIndex + 1)  == items.size()) // TODO: verify if is there a bug.
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
    if (items.size() < 2)
        return;

    if ( static_cast<size_t>(currentItemIndex + 1)  < items.size())
        currentItemIndex++;
    else
        currentItemIndex = 0;
}

void Inventory::prev()
{
    if (items.size() < 2)
        return;

    if (currentItemIndex - 1 >= 0)
        currentItemIndex--;
    else
        currentItemIndex = items.size() - 1;
}

void Inventory::drawItemSlot(sf::Vector2f initalPosition, sf::Vector2f size, bool isActive) const {
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(initalPosition);

    sf::Color gray(40, 40, 40);
    sf::Color green(0, 200, 0);

    rectangle.setOutlineColor( isActive ? green : gray );
    rectangle.setOutlineThickness(2.f);
    rectangle.setFillColor(sf::Color(0,0,0,0));
    window.draw(rectangle);
}

void Inventory::render() const
{
    constexpr float margin = 10.f;
    const float yPosition = window.getSize().y - 320;

    sf::Vertex line[] = {{{0, yPosition-20}, sf::Color::White}, {{static_cast<float>( window.getSize().x ), yPosition-20.f}, sf::Color::White}};
    window.draw(line, 4, sf::Lines);


    int i = margin;
    for (auto item: items) {
        item->render(window);
        item->sprite.setPosition(i, yPosition);
        i += slotSide + margin;
    }

    for (unsigned short i = 0; i < maxInventorySize; i++)
        drawItemSlot(sf::Vector2f(i*(slotSide) + (i+1) * (margin), yPosition), sf::Vector2f(slotSide, slotSide), currentItemIndex == i);

}
