#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>
#include <array>

class Speaker
{
private:
    std::string name;
    sf::Texture& texture;

    std::vector<std::string> texts;
    sf::Sprite sprite;

public:
    Speaker(std::string name, sf::Texture& texture);

    void addDialogueLine(const std::string dialogueLine);
    void rename(const std::string name);

    std::string& getName();
    sf::Texture& getTexture() const;
    std::vector<std::string>& getDialogueLines();
private:

};
