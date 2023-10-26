#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Character;
class Inventory;


class Item
{
    friend Character;
    friend Inventory;
public:
    Item(sf::Texture& texture);
    unsigned int getId() const;
    void render(sf::RenderWindow& window);

protected:
    unsigned int id;
    sf::Texture& texture;
    std::string name;
    sf::Sprite sprite;
public:

    static unsigned int uniqueId;

};

