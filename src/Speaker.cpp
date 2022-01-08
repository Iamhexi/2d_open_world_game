#include "../include/Speaker.hpp"

Speaker::Speaker(std::string name, sf::Texture& texture)
    : name(name), texture(texture)
{
    this->name = name;
    currentLine = 0;
}

std::string Speaker::getName() const
{
    return name;
}

void Speaker::addDialogueLine(const std::string dialogueLine)
{
    texts.push_back(dialogueLine);
}

sf::Texture& Speaker::getTexture() const
{
    return texture;
}

void Speaker::nextLine()
{
    if (currentLine < texts.size() - 1)
        currentLine++;
    else
        currentLine = 0;
}

std::size_t Speaker::getNumberOfDialogueLines()
{
    return texts.size();
}

std::string& Speaker::getDialogueLine()
{
    return texts.at(currentLine);
}
