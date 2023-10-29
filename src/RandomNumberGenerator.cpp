#include "../include/RandomNumberGenerator.hpp"

bool RandomNumberGenerator::isInitialized {false};

uint RandomNumberGenerator::generate(int lowerBound, int upperBound) {
    if (!isInitialized) {
        srand(time(NULL));
        isInitialized = true;
    }
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}