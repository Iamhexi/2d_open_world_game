#include "../include/Attacker.hpp"

Attacker::Attacker() {
    breakBetweenAttacks = sf::milliseconds(100);
    clock.restart();
}

void Attacker::attack(
    Living& target,
    const sf::FloatRect& targetPosition,
    sf::Sprite& weapon
) {
    if (clock.getElapsedTime() <= breakBetweenAttacks)
        return;

    if (!isTargetInRange(weapon.getGlobalBounds(), targetPosition))
        return;

    target.takeDamage(damage);

    clock.restart();
}

bool Attacker::isTargetInRange(const sf::FloatRect& attackerPosition, const sf::FloatRect& targetPosition) const {
    return attackerPosition.intersects(targetPosition);
}

void Attacker::startAttackAnimation(sf::Sprite& weapon) {
    weapon.rotate(10);
}