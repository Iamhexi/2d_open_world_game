#include "../include/ResourceManager.hpp"
#include <gtest/gtest.h>

TEST(ResourceManager, gettingNotExistingResourceEmitsExceptionTest) {

    ResourceManager<sf::Font> fontsManager;

    ASSERT_ANY_THROW(fontsManager.get("not_existing_font.ttf"));
}

TEST(ResourceManager, settingAlreadyExistingResourceDoesNotEmitException) {

    ResourceManager<sf::Texture> texturesManager;
    sf::Texture texture;
    texturesManager.set("t", texture);

    ASSERT_NO_THROW(texturesManager.set("t", texture));
}
