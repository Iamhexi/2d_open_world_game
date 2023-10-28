#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "RandomNumberGenerator.hpp"

class Player;
class Character;
class Inventory;


class Item
{
    friend Player;
    friend Character;
    friend Inventory;
public:
    Item(sf::Texture& texture, sf::FloatRect spawnArea = sf::FloatRect());
    unsigned int getId() const;
    void render(sf::RenderWindow& window) const;

protected:
    unsigned int id;
    sf::Texture& texture;
    std::string name;
    sf::Sprite sprite;

    void randomizePosition(sf::FloatRect areaToSpawnItem);
public:

    static unsigned int uniqueId;

};

