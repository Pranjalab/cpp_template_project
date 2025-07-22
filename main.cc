#include <iostream>
#include <chrono>

#include <gflags/gflags.h>

#include "utils/logger.h"
#include "process.h"

// CLI flags
DEFINE_string(message, "", "Optional message to append after 'Hello World!'");
DEFINE_string(name, "pipeline", "Pipeline name used for logging");

int main(int argc, char** argv) {
    // 1️⃣ Parse CLI
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    auto t0 = std::chrono::high_resolution_clock::now();

    // 3️⃣ Init logger
    Logger logger;
    const std::string pipeline_name = FLAGS_name;
    if (!logger.init(pipeline_name)) {
        std::cerr << "Error: logger init failed" << std::endl;
        return 1;
    }
    logger.info("=== Pipeline run started ===");

    // Create Process object and run
    Process proc("Hello World!");
    std::string result = proc.run(FLAGS_message);
    std::cout << result << std::endl;
    logger.info("Output: " + result);

    // timing
    auto t1 = std::chrono::high_resolution_clock::now();
    auto ms  = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
    logger.info("Total time (ms): " + std::to_string(ms));
    logger.info("=== Pipeline run finished ===");

    return 0;
}
