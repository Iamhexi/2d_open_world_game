#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../include/Living.hpp"


class Attacker {

public:
    Attacker();
    void startAttackAnimation(sf::Sprite& weapon);

    void attack(
        Living& target,
        const sf::FloatRect& targetPosition,
        sf::Sprite& weapon
    );
    

private:
    bool isTargetInRange(const sf::FloatRect& attackerPosition, const sf::FloatRect& targetPosition) const;

private:
    float damage = 3;
    sf::Clock clock;
    sf::Time breakBetweenAttacks;

    
};