#include "Item.hpp"
#include <functional>

class UseableItem: public Item
{
protected:
    std::function<void()> action;
public:
    void setAction(std::function<void()>& function);
    void use();
};
