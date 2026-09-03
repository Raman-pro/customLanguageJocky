cmake_minimum_required(VERSION 3.20)
project(jocky CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# --- LLVM discovery (Homebrew keg, or any llvm-config on PATH) -------------
find_program(LLVM_CONFIG_EXE llvm-config
    HINTS
        /opt/homebrew/opt/llvm/bin
        /usr/local/opt/llvm/bin
        /usr/lib/llvm*/bin
        $ENV{LLVM_DIR}/bin
)
if(NOT LLVM_CONFIG_EXE)
    message(FATAL_ERROR "llvm-config not found. Install LLVM or set LLVM_DIR.")
endif()

execute_process(COMMAND ${LLVM_CONFIG_EXE} --includedir
    OUTPUT_VARIABLE LLVM_INCLUDE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND ${LLVM_CONFIG_EXE} --libdir
    OUTPUT_VARIABLE LLVM_LIB_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND ${LLVM_CONFIG_EXE} --libs core irreader
    OUTPUT_VARIABLE LLVM_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND ${LLVM_CONFIG_EXE} --ldflags
    OUTPUT_VARIABLE LLVM_LDFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE)

message(STATUS "LLVM include: ${LLVM_INCLUDE_DIR}")
message(STATUS "LLVM libs:    ${LLVM_LIBS}")

add_executable(jocky
    src/main.cpp
    src/token.cpp
    src/lexer.cpp
    src/parser.cpp
    src/sema.cpp
    src/codegen.cpp
    src/obfuscate.cpp
)

target_include_directories(jocky PRIVATE ${LLVM_INCLUDE_DIR})
target_link_directories(jocky PRIVATE ${LLVM_LIB_DIR})
target_link_libraries(jocky PRIVATE ${LLVM_LIBS})

target_compile_options(jocky PRIVATE -Wall -Wextra ${LLVM_LDFLAGS})

# The forensic stdlib lives in runtime/runtime.c. The compiler shells out to a
# C compiler at --build time to compile+link the user program against it.
target_compile_definitions(jocky PRIVATE
    JOCKY_RUNTIME_C="${CMAKE_CURRENT_SOURCE_DIR}/runtime/runtime.c"
)