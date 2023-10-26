#include "include/Scene.hpp"

int main()
{
    Scene mainScene( sf::Vector2i( 1000, 1000 ) );
    
    mainScene.init();
    mainScene.run();

    return 0;
}
