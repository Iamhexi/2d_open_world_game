#include "Item.hpp"
#include <functional>

class UseableItem: public Item
{
public:
    UseableItem(sf::Texture& texture);
    void setAction(std::function<void()>& function);
    void use();
    
protected:
    std::function<void()> action;
};
