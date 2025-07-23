# C++ Template Project

A minimal C++ starter project using CMake for building, gflags for command-line argument parsing, and a simple file logger.

## Overview

This project provides a basic structure for a C++ application. It includes:

*   A `CMakeLists.txt` file that handles dependencies (like `gflags`) and builds the project.
*   A `main.cc` that demonstrates how to parse command-line arguments.
*   A simple `Process` class where you can add your core application logic.
*   A `Logger` utility that writes logs to timestamped files.

## Project Structure

```
cpp_template_project/
├── CMakeLists.txt      # Build script for CMake
├── README.md           # This file
├── main.cc             # Main executable source
├── include/            # Header files
│   ├── process.h
│   └── utils/
│       └── logger.h
├── src/                # Source files
│   ├── process.cc
│   └── utils/
│       └── logger.cc
└── build/              # Created by CMake, contains the executable
└── logs/               # Created at runtime, contains log files
```

## Getting Started

### Prerequisites

*   A C++17 compatible compiler (like g++ or clang)
*   CMake (version 3.16 or higher)

### Building the Project

1.  **Configure the project using CMake:** This will create a `build` directory and prepare the build environment. `gflags` will be downloaded automatically if not found.
    ```bash
    cmake -S . -B build
    ```

2.  **Compile the code:**
    ```bash
    cmake --build build -j
    ```
    The `-j` flag enables parallel compilation, which can speed up the process.

The executable will be created at `build/main`.

### Running the Application

You can run the application from the project root directory:

```bash
./build/main [FLAGS]
```

**Command-line Flags:**

*   `--message <string>`: An optional message to append to the "Hello World!" output.
    *   Example: `./build/main --message "How are you?"`
    *   Output: `Hello World! How are you?`
*   `--name <string>`: The name of the pipeline, used for the log file name. Defaults to `pipeline`.
    *   Example: `./build/main --name "my_test_run"`
    *   This will create a log file like `logs/run_20250722_103000/my_test_run.log`

If you run the executable without any flags, it will use the default values:
```bash
./build/main
# Output: Hello World!
```

## Customization

This project is designed to be a starting point. Here’s how you can adapt it:

*   **Add your application logic:** The core logic should go into the `Process::run` method in `src/process.cc`.
*   **Add new command-line flags:** You can define new flags in `main.cc` using the `DEFINE_string`, `DEFINE_int32`, etc. macros from `gflags`.
*   **Add new libraries:** To add new source files or link against other libraries, modify the `CMakeLists.txt` file. You can add new `add_library` or `add_executable` targets, and use `target_link_libraries` to link them together.

## Logging

The application uses a simple logger that writes messages to a file.

*   Log files are created in the `logs/` directory.
*   Each run creates a new subdirectory named `run_<timestamp>`, e.g., `logs/run_20250722_103000/`.
*   The log file itself is named after the pipeline name (from the `--name` flag), e.g., `pipeline.log`.

You can use the logger in your code by including `utils/logger.h` and calling the `info()` or `error()` methods.

## Releasing the Project

To create a release build and package it for distribution, follow these steps:

1.  **Configure the project for a release build:**
    ```bash
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    ```

2.  **Build the project:**
    ```bash
    cmake --build build -j
    ```

3.  **Package the project:**
    This command will create a distributable archive (e.g., a `.tar.gz` file) in the `build/` directory.
    ```bash
    cmake --build build --target package
    ```

4.  **Create a GitHub Release:**
    - Go to the "Releases" page of your GitHub repository.
    - Click "Draft a new release".
    - Choose a tag version (e.g., `v1.0.0`).
    - Upload the generated package from the `build/` directory.
    - Publish the release.