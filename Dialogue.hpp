#include "Speaker.hpp"

class Dialogue
{
private:
    sf::RenderWindow& window;
    sf::RectangleShape background;
    sf::Sprite speakerAvatar;
    sf::Text text;

    unsigned short progress;

    std::vector<Speaker>::iterator currentSpeaker;
    std::vector<Speaker> speakers;

public:
    Dialogue(sf::RenderWindow& window);
    void start();
    void handle();
    void addSpeaker(Speaker speaker);
    void render() const;

private:
    void toggleSpeaker();
    void loadCurrentSpeakerAvatar();
    void loadCurrentSpeakerDialogueLine();
    void setUpGrahpics();
};
