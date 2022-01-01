#include "Dialogue.hpp"

Dialogue::Dialogue(sf::RenderWindow& window)
    : window(window)
{

}

void Dialogue::start()
{
    if (speakers.size() == 0)
            throw std::string("The dialogue with no speakers cannot be started!");

    setUpGrahpics();
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

void Dialogue::addSpeaker(Speaker speaker)
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

void Dialogue::setUpGrahpics()
{
    background.setSize( sf::Vector2f( window.getSize().x, window.getSize().y/4) );
    background.setOutlineColor( sf::Color(66, 64, 62) );
    background.setFillColor( sf::Color( 99, 41, 1, 127 ) );
    background.setOutlineThickness(4);
    background.setPosition( sf::Vector2f( 0, 3.0f * window.getSize().y/4 ) );

    sf::Sprite speakerAvatar;
    sf::Text text;
}

void Dialogue::render() const
{
    window.draw(background);
    window.draw(speakerAvatar);
    window.draw(text);
}
