#include "../include/Logger.hpp"

void Logger::log(std::string message, LogLevel level)
{
    message = getCurrentTime() + ": " + message;
    eventLog.push( std::pair<std::string, LogLevel>(message, level) );
}


void Logger::saveEventLog(LogLevel level, std::string filename)
{
    if (filename.empty())
      filename = generateEventLogFilename();

    std::ofstream file( filename );

    if ( !file.is_open() || file.bad() )
        throw std::string("Couldn't create and/or open the log file " + filename + "\n");

    auto eventLogCopy = eventLog;

    while( !eventLogCopy.empty() )
    {
        if (eventLogCopy.front().second <= level)
            file << eventLogCopy.front().first << std::endl;
        eventLogCopy.pop();
    }

    file.close();
}

void Logger::printEventLog(LogLevel level )
{
    std::queue<std::pair<std::string, LogLevel>> temp = eventLog;

    while (!temp.empty())
    {
        if (temp.front().second <= level)
            std::cout << temp.front().first << std::endl;
        temp.pop();
    }
}

std::string Logger::getCurrentTime()
{
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%F %T");
    return ss.str();
}

std::string Logger::generateEventLogFilename()
{
  return replaceSpacesWithUnderscores( getCurrentTime() + ".log" );
}

void Logger::flush()
{
    eventLog = {};
}

std::string Logger::replaceSpacesWithUnderscores(const std::string& text)
{
    std::string output = "";
    for (char character: text) {
        if (character != ' ')
            output += character;
        else
            output += '_';
    }
    return output;
}
