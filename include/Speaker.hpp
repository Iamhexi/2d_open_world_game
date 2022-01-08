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

    unsigned short currentLine;
    std::vector<std::string> texts;

public:
    Speaker(std::string name, sf::Texture& texture);

    void addDialogueLine(const std::string dialogueLine);
    void nextLine();

    std::string getName() const;
    std::string& getDialogueLine();
    sf::Texture& getTexture() const;

    std::size_t getNumberOfDialogueLines();
private:

};
