#include "Item.hpp"
#include <functional>

class UseableItem: public Item
{
public:
    UseableItem(sf::Texture& texture, sf::FloatRect spawnArea);
    void setAction(std::function<void()>& function);
    void use();
    
protected:
    std::function<void()> action;
};
