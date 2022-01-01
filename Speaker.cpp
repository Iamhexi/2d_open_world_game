#include "Speaker.hpp"

Speaker::Speaker(std::string name, sf::Texture& texture)
    : name(name), texture(texture)
{

}

void Speaker::rename(const std::string name)
{
    this->name = name;
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
