cmake_minimum_required(VERSION 3.16)
project(Calculator)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON) # This handles the Q_OBJECT macro automatically!

add_executable(calculator main.cpp Calculator.cpp Calculator.h)
target_link_libraries(calculator Qt6::Widgets)
