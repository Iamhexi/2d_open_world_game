#include "Speaker.hpp"
#include <vector>

class Dialogue
{
private:
    sf::RenderWindow& window;
    sf::RectangleShape background;
    sf::Sprite speakerAvatar;
    sf::Text text;
    std::vector<Speaker> speakers;

    bool finished;
    unsigned short progress;
    unsigned short currentSpeakerId;

public:
    Dialogue(sf::RenderWindow& window, sf::Font& font);
    std::size_t getNumberOfDialogueLines();
    void start();
    void handle();
    void addSpeaker(Speaker speaker);
    void render() const;

private:
    void toggleSpeaker();
    void loadCurrentSpeakerAvatar();
    void loadCurrentSpeakerDialogueLine();
    void setUpGrahpics();
    void nextDialogueLine();
};
