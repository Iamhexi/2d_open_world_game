#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Item
{
public:
    Item(sf::Texture& texture);
    unsigned int getId() const;
    void render(sf::RenderWindow& window);

protected:
    unsigned int id;
    sf::Texture& texture;
    sf::Sprite sprite;
    std::string name;
public:

    static unsigned int uniqueId;

};

