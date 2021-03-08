cmake_minimum_required(VERSION 3.10)

project(CppCrossPlatform LANGUAGES CXX C)

# Include common settings
include(Common.cmake)

set(SOURCE_FILES
        "MyCrossPlatformClass.hpp"
        "MyCrossPlatformClass.cpp"
        "Test.hpp"
        "Test.cpp")

if(ANDROID)
    list(APPEND SOURCE_FILES
            "android/MyCrossPlatformClass.cpp"
            "android/MyCrossPlatformClass2.hpp"
            "android/MyCrossPlatformClass2.cpp"
            "android/Test.cpp"
            "android/Utilities/JniHelpers.hpp")
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
elseif(IOS)
    set(RESOURCE_FILES
            "ios/Resources/Main.storyboard")
    list(APPEND SOURCE_FILES
            "ios/MyCrossPlatformClass.mm"
            "ios/MyCrossPlatformDelegate.hpp"
            "ios/MyCrossPlatformDelegate.mm"
            "ios/Utilities/AppDelegate.hpp"
            "ios/Utilities/AppDelegate.mm"
            "ios/Utilities/main.mm"
            ${RESOURCE_FILES})
            
    # Sort sources alphabetically
    list(SORT SOURCE_FILES)
    # Keep sources grouped by file system folders
    source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCE_FILES})
    
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCE_FILES})
    
    find_library(UIKIT UIKit)
    find_library(FOUNDATION Foundation)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${UIKIT} ${FOUNDATION})
    
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
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/ios/Resources/Info.plist")
elseif(APPLE)
    set(RESOURCE_FILES
            "macos/Resources/Main.storyboard")
    list(APPEND SOURCE_FILES
            "macos/MyCrossPlatformClass.mm"
            "macos/MyCrossPlatformDelegate.hpp"
            "macos/MyCrossPlatformDelegate.mm"
            "macos/Utilities/AppDelegate.hpp"
            "macos/Utilities/AppDelegate.mm"
            "macos/Utilities/main.mm"
            ${RESOURCE_FILES})
            
    # Sort sources alphabetically
    list(SORT SOURCE_FILES)
    # Keep sources grouped by file system folders
    source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCE_FILES})
    
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCE_FILES})
    
    find_library(APP_KIT AppKit)
    find_library(FOUNDATION Foundation)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${APP_KIT} ${FOUNDATION})
    
    # Set resources
    set_target_properties(${PROJECT_NAME} PROPERTIES RESOURCE "${RESOURCE_FILES}")
    # Disable emitting bitcode
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_ENABLE_BITCODE NO)
    # Enable automatic reference counting
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC YES)
    # Make Xcode manage library linking
    set_target_properties(${PROJECT_NAME} PROPERTIES XCODE_LINK_BUILD_PHASE_MODE KNOWN_LOCATION)
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/macos/Resources/Info.plist")
elseif(WIN32)
    list(APPEND SOURCE_FILES
            "windows/MyCrossPlatformClass.cpp"
            "windows/Utilities/main.cpp")

    # Sort sources alphabetically
    list(SORT SOURCE_FILES)
    # Keep sources grouped by file system folders
    source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCE_FILES})

    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
else()
    message(FATAL_ERROR "Unknown target platform")
endif()
