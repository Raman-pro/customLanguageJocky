cmake_minimum_required(VERSION 3.20)
project(jocky CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(jocky
    src/main.cpp
    src/token.cpp
    src/lexer.cpp
    src/parser.cpp
    src/sema.cpp
    src/codegen.cpp
    src/obfuscate.cpp
    src/postprocess.cpp
)

target_compile_options(jocky PRIVATE -Wall -Wextra)