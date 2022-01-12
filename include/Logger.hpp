#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <queue>

#ifndef LOGGER_HPP
#define LOGGER_HPP

enum LogLevel
{
    Error,
    Warning,
    Info,
    Debug
};

class Logger {
public:
    static Logger* logger;
    static Logger& getInstance()
    {
        static Logger* logger = new Logger();
        return *logger;
    }


  void log(std::string message, LogLevel level);
  void printEventLog(LogLevel level = LogLevel::Warning);
  void flush();
  void saveEventLog(LogLevel level = LogLevel::Debug, std::string filename = "");

private:
  Logger(){}
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
  Logger(Logger&&) = delete;
  Logger& operator=(Logger&&) = delete;

  std::string getCurrentTime();
  std::string replaceSpacesWithUnderscores(const std::string& text);
  std::string generateEventLogFilename();

private:
    std::queue<std::pair<std::string, LogLevel>> eventLog;
};

#endif
