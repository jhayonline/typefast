cmake_minimum_required(VERSION 3.14)
project(TypingTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

# Find FTXUI
find_package(ftxui REQUIRED)

add_executable(typing_test 
    src/main.cpp
    src/TypingTest.cpp
    src/WordBank.cpp
)

target_link_libraries(typing_test 
    ftxui::screen
    ftxui::dom
    ftxui::component
    ftxui::util
)

target_include_directories(typing_test PRIVATE src)
