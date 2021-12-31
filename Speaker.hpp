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
    Speaker(std::string& name, sf::Texture& texture);

    void addDialogueLine(std::string& dialogueLine);
    void rename(const std::string& name);

    sf::Texture& getTexture();
    std::vector<std::string>& getDialogueLines();
private:

};
