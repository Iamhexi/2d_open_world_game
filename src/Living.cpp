#include "../include/Living.hpp"

bool Living::isAlive() const {
    return health > 0.f;
}

void Living::healDamage(float amount) {
    if (amount <= 0.f)
        return;
    
    health += amount;
    if (health > maxHealth)
        health = maxHealth;
}

void Living::takeDamage(float amount) {
    if (amount <= 0.f)
        return;

    health -= amount;
    if (health < 0.f)
       health = 0.f; 
}
