#include "_TestTools.cpp"
#include "../headers/Speaker.hpp"

void addDialogueLineTest()
{
    Tests::TEST(__FUNCTION__);

    sf::Texture t;
    Speaker speaker("Johh", t);
    std::string line = "Hey, you little boi!";

    speaker.addDialogueLine(line);

    Tests::ASSERT_EQUAL( speaker.getDialogueLines().at(0), line );
}
