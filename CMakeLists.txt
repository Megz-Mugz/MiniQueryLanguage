cmake_minimum_required(VERSION 3.26)
project(MiniQueryLanguage LANGUAGES CXX)

# Enforce C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Executable
add_executable(MiniQueryLanguage
        src/main.cpp
        src/lexer/lexer.cpp
        # add other .cpp files here
)

# Include headers from src/
target_include_directories(MiniQueryLanguage PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)