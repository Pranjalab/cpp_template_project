#include "process.h"
#include <utility>

Process::Process(std::string base_msg) : base_msg_(std::move(base_msg)) {}
Process::~Process() = default;

std::string Process::run(const std::string& suffix) const {
    if (suffix.empty()) return base_msg_;
    return base_msg_ + " " + suffix;
}
