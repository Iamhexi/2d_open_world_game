#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class Item
{
protected:
    unsigned int id;
    std::unique_ptr<sf::Texture> texture;
    sf::Sprite sprite;
    std::string name;
public:
    static unsigned int uniqueId;

public:
    Item();
    unsigned int getId() const;

protected:
    void assignId();
};
