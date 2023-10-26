#include "../include/UseableItem.hpp"
#include <iostream>

UseableItem::UseableItem(sf::Texture& texture, sf::FloatRect spawnArea)
    : Item(texture, spawnArea)
{

}

void UseableItem::setAction(std::function<void()>& function)
{
    this->action = function;
}

void UseableItem::use()
{
    try {
        action();
    } catch (std::bad_function_call e){
        std::cout << e.what() << ": the UseableItem without an assigned action was used.\n";
    }
}
