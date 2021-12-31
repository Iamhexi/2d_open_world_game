#include "Dialogue.hpp"

// TODO: Rewrite to use Iterator instead of currentSpeakerIndex variable

void Dialogue::start()
{
    if (speakers.size() == 0)
            throw std::string("The dialogue with no speakers cannot be started!");

    progress = 0;
    currentSpeakerIndex = 0;
    currentSpeaker = std::make_unique<Speaker> ( speakers.at(0) );
}

void Dialogue::handle()
{
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ) )
    {
        toggleSpeaker();
        loadCurrentSpeakerAvatar();
        loadCurrentSpeakerDialogueLine();
    }

}

void Dialogue::loadCurrentSpeakerDialogueLine()
{
    text = currentSpeaker->getDialogueLines().at(progress);
}

void Dialogue::loadCurrentSpeakerAvatar()
{
    speakerAvatar.setTexture( currentSpeaker->getTexture() );
}

void Dialogue::createSpeaker(Speaker speaker)
{
    speakers.push_back(speaker);
}

void Dialogue::toggleSpeaker()
{
    if (currentSpeakerIndex >= speakers.size())
        currentSpeakerIndex++;
    else
        currentSpeakerIndex = 0;

    currentSpeaker = std::make_unique<Speaker>( speakers.at(currentSpeakerIndex) );
}

void Dialogue::render(sf::RenderWindow& window) const;
{
    window.draw(background);
    window.draw(speakerAvatar);
    window.draw(text);
}
