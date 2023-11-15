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

protected:
    void randomizePosition(sf::FloatRect areaToSpawnItem);

public:
    sf::Sprite sprite;
    static unsigned int uniqueId;

};

