#include "Speaker.hpp"

Speaker::Speaker(std::string& name, sf::Texture& texture)
    : name(name), texture(texture)
{

}

void Speaker::rename(const std::string& name)
{
    this->name = name;
}

void Speaker::addDialogueLine(std::string& dialogueLine)
{
    texts.push_back(dialogueLine);
}

sf::Texture& Speaker::getTexture()
{
    return texture;
}

std::vector<std::string>& Speaker::getDialogueLines()
{
    return texts;
}
