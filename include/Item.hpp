#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Item
{
public:
    unsigned int getId() const;
    void render(sf::RenderWindow& window);

protected:
    Item(sf::Texture& texture);
    void assignId();

protected:
    unsigned int id;
    sf::Texture& texture;
    sf::Sprite sprite;
    std::string name;
public:

    static unsigned int uniqueId;

};

