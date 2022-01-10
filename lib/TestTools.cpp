#include <iostream>
#include <iomanip>

#ifndef TEST_TOOLS
#define TEST_TOOLS

namespace Tests {

    const char* currentTestName = "Any test hasn't been set yet";
    int failedTests = 0;
    int totalTests = 0;

    void TEST(const char* testName)
    {
        currentTestName = testName;
        totalTests++;
    }

    void testFailed()
    {
         std::cout << "\033[0;31m" << currentTestName << " failed!" << "\033[0m\n";
         failedTests++;
    }

    void ASSERT(auto phrase)
    {
        if (!phrase)
            testFailed();
    }

    void ASSERT_FALSE(auto phrase)
    {
        if (phrase)
            testFailed();
    }

    void ASSERT_EQUAL(auto phrase1, auto phrase2)
    {
        if (phrase1 != phrase2)
            testFailed();
    }

    void ASSERT_NOT_EQUAL(auto phrase1, auto phrase2)
    {
        if (phrase1 == phrase2)
            testFailed();
    }

    void runSummary()
    {
        if (failedTests > 0)
            std::cout << "\033[0;31m" << failedTests << " of " << totalTests << " tests failed!" << "\033[0m\n";
        else
            std::cout << "\033[0;32m" << "All " << totalTests << " tests passed." << "\033[0m\n";
    }
};

#endif
