#include "../include/UseableItem.hpp"
#include <iostream>

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
