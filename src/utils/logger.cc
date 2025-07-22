#include "utils/logger.h"
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <iostream>

static std::string currentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto t   = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    return oss.str();
}

Logger::~Logger() {
    if (ofs_.is_open()) ofs_.close();
}

bool Logger::init(const std::string& pipeline_name) {
    std::string ts  = currentTimestamp();
    std::string dir = "logs/run_" + ts;
    std::filesystem::create_directories(dir);
    ofs_.open(dir + "/" + pipeline_name + ".log", std::ios::out);
    return ofs_.is_open();
}

void Logger::info(const std::string& msg) {
    if (ofs_.is_open()) ofs_ << "[INFO] " << msg << std::endl;
}

void Logger::error(const std::string& msg) {
    if (ofs_.is_open()) ofs_ << "[ERROR] " << msg << std::endl;
}