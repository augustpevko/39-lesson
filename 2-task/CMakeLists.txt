cmake_minimum_required(VERSION 3.0.0)
project(2-task VERSION 0.1.0)

set(SOURCES main.cpp)

set(CMAKE_PREFIX_PATH "/home/pavel/Qt/5.15.2/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(2-task ${SOURCES})

target_link_libraries(2-task Qt5::Core Qt5::Widgets)
target_include_directories(2-task PUBLIC ${MY_INCLUDE_DIR})