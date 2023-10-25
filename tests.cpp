#include "tests/SpeakerTest.cpp"
#include "tests/ResourceManagerTest.cpp"
#include "tests/LoggerTest.cpp"
#include <gtest/gtest.h>

int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

