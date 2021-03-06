cmake_minimum_required(VERSION 3.10)

project(CppCorssPlatform LANGUAGES CXX C)

# Include common settings
include(Common.cmake)

set(SOURCE_FILES "main.cpp")

if(ANDROID)
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
else()
    message(FATAL_ERROR "Unknown target platform")
endif()
