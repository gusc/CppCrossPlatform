cmake_minimum_required(VERSION 3.10)

project(CppCorssPlatform LANGUAGES CXX C)

# Include common settings
include(Common.cmake)

set(SOURCE_FILES
        "MyCrossPlatformClass.hpp"
        "MyCrossPlatformClass.cpp")

if(ANDROID)
    list(APPEND SOURCE_FILES
            "android/MyCrossPlatformClass.cpp"
            "android/Utilities/JniHelpers.hpp")
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
else()
    message(FATAL_ERROR "Unknown target platform")
endif()
