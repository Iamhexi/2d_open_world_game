#include "tests/SpeakerTest.cpp"
#include "tests/ResourceManagerTest.cpp"
#include "tests/LoggerTest.cpp"

int main()
{
    addDialogueLineTest();

    gettingNotExistingResourceDoesNotEmitExceptionTest();
    settingAlreadyExistingResourceDoesNotEmitExceptionTest();

    testCreatingEventLogFile();

    Tests::runSummary();
    return 0;
}
