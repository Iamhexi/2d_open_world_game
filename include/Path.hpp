#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Logger.hpp"
#include "RandomNumberGenerator.hpp"

class Path {

public:
    Path(sf::RenderWindow& window);
    void setRepeatable(bool value);
    void generateRandomPath(size_t destinationCount = 5);

    void addDestination(const sf::Vector2f& destination);
    void markDestinationAsCompleted(const sf::Vector2f& destination);
    const sf::Vector2f& getCurrentDestination();

private:
    void restart();

private:
    sf::RenderWindow& window;
    std::vector<std::pair<sf::Vector2f, bool>> path; // destinationPoint, isVisited
    bool repeatable {true};
};