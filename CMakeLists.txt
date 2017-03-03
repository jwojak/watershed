# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.

cmake_minimum_required (VERSION 2.6)
project(watershed)

add_executable(watershed progtest.cpp cppimage.cpp vincent_soille_watershed.cpp)
