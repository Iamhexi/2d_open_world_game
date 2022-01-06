all:
	g++ src/* main.cpp -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -std=c++20 -Wextra -Wpedantic -o bin/run && ./bin/run
test:
	g++ tests/tests.cpp src/* -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -std=c++20 -Wextra -Wpedantic -o bin/test && ./bin/test
