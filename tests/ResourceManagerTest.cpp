#include "../include/ResourceManager.hpp"
#include "../lib/TestTools.cpp"

using namespace Tests;

void gettingNotExistingResourceDoesNotEmitExceptionTest()
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

void settingAlreadyExistingResourceDoesNotEmitExceptionTest()
{
    TEST(__FUNCTION__);

    bool exceptionThrown = false;
    ResourceManager<sf::Texture> texturesManager;
    sf::Texture texture;
    texturesManager.set("t", texture);

    try {
        texturesManager.set("t", texture);
    } catch (...){
        exceptionThrown = true;
    }

    ASSERT_FALSE(exceptionThrown);
}
