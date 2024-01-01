#pragma once
#include <SFML/Graphics.hpp>

class Living {

public:
    bool isAlive() const;
    void healDamage(float amount);
    void takeDamage(float amount);

private:
    float health = 10;
    float maxHealth = 10;
};
