#include <SFML/Graphics.hpp>

class Character
{
private:
    sf::RenderWindow& window;
    sf::Texture& texture;
    sf::Sprite sprite;
    float speed = 3.5f;
    bool canMove = true;
public:
    Character(sf::RenderWindow& window, sf::Texture& texture, sf::Vector2f startingPosition);
    void handleMovement();
    void render() const;
private:
    void moveUpIfPossible();
    void moveDownIfPossible();
    void moveRightIfPossible();
    void moveLeftIfPossible();
};
