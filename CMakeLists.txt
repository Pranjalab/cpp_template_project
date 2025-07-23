cmake_minimum_required(VERSION 3.16)
project(cpp_template_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# ---- gflags via FetchContent ----
include(FetchContent)
FetchContent_Declare(
  gflags
  GIT_REPOSITORY https://github.com/gflags/gflags.git
  GIT_TAG        v2.2.2
)
FetchContent_MakeAvailable(gflags)

# ---- Logger lib ----
add_library(logger
    src/utils/logger.cc
)
target_include_directories(logger PUBLIC include)

# ---- Process lib ----
add_library(process
    src/process.cc
)
target_include_directories(process PUBLIC include)

# ---- Main exe ----
add_executable(main
    main.cc
)
target_link_libraries(main PRIVATE process logger gflags)

# Output directory
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Optional install
install(TARGETS main process logger)
install(DIRECTORY include/ DESTINATION include)

# ---- CPack configuration ----
include(CPack)

set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A C++ template project")
set(CPACK_PACKAGE_VENDOR "Gemini")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_NAME}")
set(CPACK_SET_DESTDIR ON)
