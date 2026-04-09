cmake_minimum_required(VERSION 3.10)
project(QtCalculator)

# Enable automatic Qt features
set(CMAKE_AUTOMOC ON) 

# Find Qt6 (Corrected the spelling of REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(QtCalculator
    main.cpp
    mainwindow.h
    mainwindow.cpp
)

target_link_libraries(QtCalculator Qt6::Widgets)
