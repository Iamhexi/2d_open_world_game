#include "Dialogue.hpp"
#include <iostream>

Dialogue::Dialogue(sf::RenderWindow& window, sf::Font& font)
    : window(window)
{
    finished = false;
    progress = 0;

    text.setFont(font);
    text.setString("");
    text.setCharacterSize(30);
    text.setFillColor( sf::Color(0, 0, 0) );
}

void Dialogue::start()
{
    if (speakers.size() == 0)
            throw std::string("The dialogue with no speakers cannot be started!");

    currentSpeakerId = 0;
    setUpGrahpics();
    progress = 0;
    finished = false;
}

void Dialogue::handle()
{
    if (finished)
        return;

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ) )
    {
        loadCurrentSpeakerAvatar();
        loadCurrentSpeakerDialogueLine();
        toggleSpeaker();
    }

}

void Dialogue::loadCurrentSpeakerDialogueLine()
{
    text.setString( speakers.at(currentSpeakerId).getDialogueLines().at(progress) );
}

void Dialogue::loadCurrentSpeakerAvatar()
{
    speakerAvatar.setTexture( speakers.at(currentSpeakerId).getTexture() );
}

void Dialogue::addSpeaker(Speaker speaker)
{
    speakers.push_back(speaker);
}

void Dialogue::toggleSpeaker()
{
    if ( currentSpeakerId < speakers.size() - 1 )
    {
        currentSpeakerId++;
    }
    else
    {
        currentSpeakerId = 0;
        progress++;
    }

    if ( progress >= speakers.at(currentSpeakerId).getDialogueLines().size() )
        finished = true;

    // TODO: after altering a speaker, pause for exactly one second, not to let the user skip dialogue lines needlessly
}

void Dialogue::setUpGrahpics()
{
    background.setSize( sf::Vector2f( window.getSize().x, window.getSize().y/4) );
    background.setOutlineColor( sf::Color(66, 64, 62) );
    background.setFillColor( sf::Color( 99, 41, 1, 127 ) );
    background.setOutlineThickness(4);
    background.setPosition( sf::Vector2f( 0, 3.0f * window.getSize().y/4 ) );

    // TODO: set up a speaker's avatar and dialogue the line position
}

void Dialogue::render() const
{
    if (!finished)
    {
        window.draw(background);
        window.draw(speakerAvatar);
        window.draw(text);
    }
}
