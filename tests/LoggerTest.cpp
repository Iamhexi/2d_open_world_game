#include "../lib/TestTools.cpp"
#include "../include/Logger.hpp"
#include <filesystem>

using namespace Tests;

void testCreatingEventLogFile()
{
    TEST(__FUNCTION__);

    Logger::getInstance().log("Example log content", LogLevel::DEBUG);
    Logger::getInstance().saveEventLog(LogLevel::DEBUG);
    std::string filename = "*";
    std::filesystem::path p("../log/" + filename);

    ASSERT(std::filesystem::exists(p));


}
