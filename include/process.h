#pragma once
#include <string>

class Process {
public:
    explicit Process(std::string base_msg = "Hello World!");
    ~Process();

    Process(const Process&) = delete;
    Process& operator=(const Process&) = delete;

    std::string run(const std::string& suffix) const;

private:
    std::string base_msg_;
};
