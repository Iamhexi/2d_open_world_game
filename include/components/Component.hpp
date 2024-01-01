#include <memory>
#include <SFML/Graphics.hpp>
using ComponentPtr = std::shared_ptr<Component>;

class Component {

public:
    virtual bool intersects(ComponentPtr other) const = 0;
    virtual void move(const sf::Vector2f& movement) = 0;

};