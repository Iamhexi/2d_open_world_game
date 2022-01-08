#include "../lib/TestTools.cpp"
#include "../include/Speaker.hpp"

void addDialogueLineTest()
{
    Tests::TEST(__FUNCTION__);

    sf::Texture t;
    Speaker speaker("Johh", t);
    std::string line = "Hey, you little boi!";

    speaker.addDialogueLine(line);

    Tests::ASSERT_EQUAL( speaker.getDialogueLine(), line );
}
