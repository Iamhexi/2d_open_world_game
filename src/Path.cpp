#include "../include/Path.hpp"

using pathPair = std::pair<sf::Vector2f, bool>;

Path::Path(sf::RenderWindow& window): window(window) {

}

void Path::setRepeatable(bool value) {
    repeatable = value;
}

void Path::restart() {
    for (auto& destination : path)
        destination.second = false;
}

void Path::generateRandomPath(size_t destinationCount) {
    path.clear();

    RandomNumberGenerator rng;
    for (size_t i = 0; i < destinationCount; i++) {
        path.emplace_back(
            pathPair(
                sf::Vector2f( // TODO: take into account rectangle inside which NPC should move, pass texture size. Do NOT hardcore it here.
                    static_cast<float>(rng.generate( 100, window.getSize().x - 200 )), 
                    static_cast<float>(rng.generate( 200, window.getSize().y - 540)) 
                ),
                false
            )
        );
    }
}

void Path::addDestination(const sf::Vector2f& destination) {
    path.push_back(pathPair(destination, false));
}

void Path::markDestinationAsCompleted(const sf::Vector2f& destination) {
    auto result = std::find(path.begin(), path.end(), pathPair(destination, false));
    if (result != path.end())
        result->second = true;

    Logger::getInstance().log(
        "Cannot mark destination as completed because it does not exist or was already marked as completed.",
        LogLevel::Warning
    );
}

const sf::Vector2f& Path::getCurrentDestination() {
    for (const auto& destination : path)
        if (destination.second == false)
            return destination.first;

    if (repeatable) {
        restart();
        return path.begin()->first;
    } else {
        return path.end()->first;
    }
}
