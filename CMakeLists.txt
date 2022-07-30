cmake_minimum_required(VERSION 3.22)
project(green)

set(CMAKE_CXX_STANDARD 23)

set(BUILD_ARCH "-m64")
set(TARGET_64 ON)

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


add_executable(green main.cpp src/parser.cpp src/parser.h src/logging.h)

add_subdirectory(src)

llvm_map_components_to_libnames(llvm_libs
    Analysis
    Core
    ExecutionEngine
    InstCombine
    Object
    OrcJIT
    RuntimeDyld
    ScalarOpts
    Support
    native
)

target_link_libraries(green ${llvm_libs})