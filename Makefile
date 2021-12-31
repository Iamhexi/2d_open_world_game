main:
	g++ main.cpp Character.cpp ResourceManager.cpp Speaker.cpp Dialogue.cpp -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -std=c++20 -Wextra -o run
