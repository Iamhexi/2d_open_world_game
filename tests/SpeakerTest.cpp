#include "../include/Speaker.hpp"
#include <gtest/gtest.h>

TEST(Speaker, requestingDialogueLineReturnsRecentlyAddedDialogueLine) {
    sf::Texture t;
    Speaker speaker("John", t);
    std::string line = "Hey, you little boi!";

    speaker.addDialogueLine(line);

    ASSERT_EQ(speaker.getDialogueLine(), line);
}