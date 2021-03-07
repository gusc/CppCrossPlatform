cmake_minimum_required(VERSION 3.10)

project(CppCrossPlatform LANGUAGES CXX C)

# Include common settings
include(Common.cmake)

set(SOURCE_FILES
        "MyCrossPlatformClass.hpp"
        "MyCrossPlatformClass.cpp")

if(ANDROID)
    list(APPEND SOURCE_FILES
            "android/MyCrossPlatformClass.cpp"
            "android/MyCrossPlatformClass2.hpp"
            "android/MyCrossPlatformClass2.cpp"
            "android/Utilities/JniHelpers.hpp")
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
elseif(IOS)
    set(RESOURCE_FILES
            "MainStoryboard.storyboard")
    list(APPEND SOURCE_FILES
            "ios/MyCrossPlatformClass.mm"
            "ios/MyCrossPlatformDelegate.hpp"
            "ios/MyCrossPlatformDelegate.mm"
            ${RESOURCE_FILES})
            
    # Sort sources alphabetically
    list(SORT SOURCE_FILES)
    # Keep sources grouped by file system folders
    source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCE_FILES})
    
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCE_FILES})
    
    # Set resources
    set_target_properties(${PROJECT_NAME} PROPERTIES RESOURCE "${RESOURCE_FILES}")
    # Target iOS
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_SDKROOT "iphoneos")
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_SUPPORTED_PLATFORMS "iphonesimulator iphoneos")
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_VALID_ARCHS "arm64")
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "11.0")
    # Disable emitting bitcode
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_ENABLE_BITCODE NO)
    # Enable automatic reference counting
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC YES)
    # Make Xcode manage library linking
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_LINK_BUILD_PHASE_MODE KNOWN_LOCATION)
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/Info.plist")
else()
    message(FATAL_ERROR "Unknown target platform")
endif()
