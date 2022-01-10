#include "tests/SpeakerTest.cpp"
#include "tests/ResourceManagerTest.cpp"

int main()
{
    addDialogueLineTest();
    gettingNotExistingResourceDoesNotProduceExceptionTest();

    Tests::runSummary();
    return 0;
}
