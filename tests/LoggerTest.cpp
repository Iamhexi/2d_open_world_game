#include "../include/Logger.hpp"
#include <filesystem>
#include <gtest/gtest.h>

TEST(Logger, savingExampleLogToNewLogFile) {
    const char* filename = "testEventLogFile.log";
    Logger::getInstance().log("Example log content", LogLevel::Debug);
    Logger::getInstance().saveEventLog(LogLevel::Debug, filename);

    std::filesystem::path p(filename);
    ASSERT_TRUE(std::filesystem::exists(p));
}