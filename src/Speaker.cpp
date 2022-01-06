#include "../headers/Speaker.hpp"

Speaker::Speaker(std::string name, sf::Texture& texture)
    : name(name), texture(texture)
{
    this->name = name;
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

std::vector<std::string>& Speaker::getDialogueLines()
{
    return texts;
}
