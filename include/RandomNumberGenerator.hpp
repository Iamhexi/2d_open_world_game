#include <ctime>
#include <cstdlib>

class RandomNumberGenerator {

public:
    static uint generate(int lowerBound, int upperBound);
    
private:
    static bool isInitialized;
};