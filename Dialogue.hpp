#include "Speaker.hpp"

class Dialogue
{
private:
    sf::RectangleShape background;
    sf::Sprite speakerAvatar;
    sf::Text text;

    unsigned short progress;
    unsigned short currentSpeakerIndex;

    std::vector<Speaker> speakers;
    std::unique_ptr<Speaker> currentSpeaker;

public:
    void start();
    void handle();
    void createSpeaker(Speaker speaker);
    void render(sf::RenderWindow& window) const;

private:
    void toggleSpeaker();
    void loadCurrentSpeakerAvatar();
    void loadCurrentSpeakerDialogueLine();
};
