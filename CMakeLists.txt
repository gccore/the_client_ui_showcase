cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
cmake_policy(SET CMP0100 NEW)

project(the_client_ui_showcase LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cc)
