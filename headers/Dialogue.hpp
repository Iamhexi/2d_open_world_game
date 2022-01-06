#include "Speaker.hpp"
#include <vector>

class Dialogue
{
private:
    sf::RenderWindow& window;
    sf::RectangleShape background;
    sf::Sprite speakerAvatar;
    sf::Text text;

    unsigned short progress;
    bool finished;

    unsigned short currentSpeakerId;
    std::vector<Speaker> speakers;

public:
    Dialogue(sf::RenderWindow& window, sf::Font& font);
    void start();
    void handle();
    void addSpeaker(Speaker speaker);
    void render() const;

private:
    void toggleSpeaker();
    void loadCurrentSpeakerAvatar();
    void loadCurrentSpeakerDialogueLine();
    void setUpGrahpics();
    void removeSaidDialogueLines();
};
