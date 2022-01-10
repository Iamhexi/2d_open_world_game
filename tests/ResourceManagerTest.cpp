#include "../include/ResourceManager.hpp"
#include "../lib/TestTools.cpp"

using namespace Tests;

void gettingNotExistingResourceDoesNotProduceExceptionTest()
{

    TEST(__FUNCTION__);

    ResourceManager<sf::Font> fontsManager;
    bool exceptionThrown = false;

    try {
        fontsManager.get("not_existing_font.ttf");
    } catch (...){
        exceptionThrown = true;
    }
        ASSERT_FALSE(exceptionThrown);

}
