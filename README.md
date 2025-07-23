# C++ Project Template

[![build](https://github.com/Pranjalab/cpp_template_project/actions/workflows/ci.yml/badge.svg)](https://github.com/Pranjalab/cpp_template_project/actions/workflows/ci.yml)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/Pranjalab/cpp_template_project)](https://github.com/Pranjalab/cpp_template_project/releases)[![GitHub license](https://img.shields.io/github/license/Pranjalab/cpp_template_project)](LICENSE)

A modern, feature-rich C++ project template designed for robustness and ease of use. This template provides a complete development workflow, from building and testing to releasing, all powered by CMake.

## Features

- **Modern C++:** Uses C++17 for modern language features.
- **CMake Build System:** A powerful and flexible build system that handles dependencies and build configurations.
- **Dependency Management:** Uses `FetchContent` to automatically download and manage dependencies like `gflags`.
- **Command-Line Parsing:** Integrated with `gflags` for easy command-line argument parsing.
- **Structured Logging:** A simple but effective logger that writes to timestamped files.
- **Release Packaging:** CPack configuration is included to easily create distributable packages.
- **Clear Project Structure:** A logical and scalable project structure.

## Getting Started

### Prerequisites

- A C++17 compatible compiler (e.g., GCC, Clang, MSVC)
- CMake (version 3.16 or higher)
- Git

### Installation

1.  **Clone the repository:**
    ```bash
    git clone <your-repository-url>
    cd <your-project-directory>
    ```

2.  **Configure the project:**
    This will create a `build` directory and prepare the build environment.
    ```bash
    cmake -S . -B build
    ```

3.  **Compile the code:**
    ```bash
    cmake --build build -j
    ```
    The executable will be created at `build/main`.

## Using this Template for Your Own Project

To use this repository as a template for your own C++ project, follow these steps:

1.  **Fork the repository:** Go to the GitHub page of this template and click the "Fork" button. This will create a copy of the repository under your GitHub account.
2.  **Clone your forked repository:**
    ```bash
    git clone https://github.com/YOUR_USERNAME/YOUR_FORKED_REPO_NAME.git
    cd YOUR_FORKED_REPO_NAME
    ```
3.  **Rename your project:**
    *   **Update `CMakeLists.txt`:** Change the `project()` name in the top-level `CMakeLists.txt` file to your desired project name.
    *   **Rename executable (optional):** If you want your main executable to have a different name than `main`, you can change `add_executable(main ...)` in `CMakeLists.txt` to `add_executable(YOUR_PROJECT_NAME ...)` and also update any references to `build/main` in the README.
4.  **Customize your code:**
    *   Modify `main.cc`, `include/process.h`, `src/process.cc`, and `include/utils/logger.h`, `src/utils/logger.cc` to implement your project's specific logic.
    *   Add new source files and headers as needed, and update `CMakeLists.txt` to include them in your build.
5.  **Update README.md:** Customize this `README.md` file with information specific to your project, including its purpose, features, and usage instructions.
6.  **Remove `.git` history (optional):** If you want to start with a clean Git history for your new project, you can remove the existing `.git` directory and reinitialize Git:
    ```bash
    rm -rf .git
    git init
    git add .
    git commit -m "Initial commit for my new project"
    ```
    Then, link it to a new empty repository on GitHub.
7.  **Set up GitHub Actions (optional):** If you forked the repository, the GitHub Actions workflow (`.github/workflows/ci.yml`) should work automatically. If you created a new repository, you might need to copy the workflow file.

Now you have a new C++ project based on this template, ready for your development!

## Development Workflow

This template provides a structured workflow for developing your C++ application.

### 1. Building your Algorithm

The core application logic resides in the `Process` class.

- **`include/process.h`**: Header file for the `Process` class.
- **`src/process.cc`**: Implementation of the `Process` class.

Modify the `Process::run` method in `src/process.cc` to implement your main algorithm. You can add new classes and files as needed and update the `CMakeLists.txt` to include them in the build.

### 2. Building the Project

To build the project, run the following commands from the project root:

- **Debug Build (for development):**
  ```bash
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
  cmake --build build -j
  ```

- **Release Build (for performance):**
  ```bash
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
  cmake --build build -j
  ```

### 3. Testing the Project

_(Note: This section is a placeholder. You can add your testing framework of choice, such as GTest, and add the necessary CMake configuration.)_

A robust testing setup is crucial for any project. We recommend using a testing framework like [Google Test](https://github.com/google/googletest).

To add testing to this project, you would typically:
1.  Add GTest as a dependency in `CMakeLists.txt` using `FetchContent`.
2.  Create a `tests/` directory with your test files.
3.  Add a `add_test` command in `CMakeLists.txt` to define your tests.
4.  Run the tests using `ctest` from the `build` directory.

### 4. Releasing the Package

When you are ready to release your project, you can create a distributable package.

1.  **Configure for Release:**
    ```bash
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    ```

2.  **Build the Project:**
    ```bash
    cmake --build build -j
    ```

3.  **Create the Package:**
    This will create a `.tar.gz` archive in the `build/` directory.
    ```bash
    cmake --build build --target package
    ```

4.  **Create a GitHub Release:**
    - Go to the "Releases" page of your GitHub repository.
    - Click "Draft a new release".
    - Choose a tag version (e.g., `v1.0.0`).
    - Upload the generated package from the `build/` directory.
    - Publish the release.

## Contributing

Contributions are welcome! If you have a suggestion or find a bug, please open an issue or submit a pull request.

### Pull Request Process

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/your-feature`).
3.  Make your changes.
4.  Commit your changes (`git commit -m 'Add some feature'`).
5.  Push to the branch (`git push origin feature/your-feature`).
6.  Open a pull request.

## Contributors


<a href="https://github.com/Pranjal-neo" align="center">
  <img src="https://github.com/Pranjal-neo.png" alt="Pranjal" width="100" height="100" style="border-radius:50%;" />
</a>  
  
**Pranjal Bhaskare** 
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
