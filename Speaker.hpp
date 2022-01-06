#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include <list>

class Speaker
{
private:
    std::string name;
    sf::Texture& texture;

    std::vector<std::string> texts;

public:
    Speaker(std::string name, sf::Texture& texture);

    void addDialogueLine(const std::string dialogueLine);

    std::string getName() const;
    sf::Texture& getTexture() const;
    std::vector<std::string>& getDialogueLines();
private:

};
