#include "../lib/TestTools.cpp"
#include "../include/Logger.hpp"
#include <filesystem>

using namespace Tests;

void testCreatingEventLogFile()
{
    TEST(__FUNCTION__);

    const char* filename = "testEventLogFile.log";
    Logger::getInstance().log("Example log content", LogLevel::Debug);
    Logger::getInstance().saveEventLog(LogLevel::Debug, filename);

    std::filesystem::path p(filename);

    ASSERT(std::filesystem::exists(p));


}
