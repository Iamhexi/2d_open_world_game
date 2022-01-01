#include "Dialogue.hpp"

// TODO: Rewrite to use Iterator instead of currentSpeakerIndex variable

void Dialogue::start()
{
    if (speakers.size() == 0)
            throw std::string("The dialogue with no speakers cannot be started!");

    currentSpeaker = speakers.begin();
    progress = 0;
}

void Dialogue::handle()
{
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ) )
    {
        toggleSpeaker();
        loadCurrentSpeakerAvatar();
        loadCurrentSpeakerDialogueLine();

        if ( currentSpeaker == speakers.end() )
            progress++;
    }

}

void Dialogue::loadCurrentSpeakerDialogueLine()
{
    text.setString( currentSpeaker->getDialogueLines().at(progress) );
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
    if ( currentSpeaker != speakers.end() )
        currentSpeaker++;
    else
        currentSpeaker = speakers.begin();
}

void Dialogue::render(sf::RenderWindow& window) const
{
    window.draw(background);
    window.draw(speakerAvatar);
    window.draw(text);
}
