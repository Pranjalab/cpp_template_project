#pragma once
#include <string>
#include <fstream>

// Simple file logger: writes to logs/run_<timestamp>/<pipeline>.log
class Logger {
public:
    Logger() = default;
    ~Logger();

    bool init(const std::string& pipeline_name);
    void info(const std::string& msg);
    void error(const std::string& msg);

private:
    std::ofstream ofs_;
};
