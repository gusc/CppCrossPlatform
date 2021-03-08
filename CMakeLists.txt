cmake_minimum_required(VERSION 3.10)

project(CppCrossPlatform LANGUAGES CXX C)

# Include common settings
include(Common.cmake)

set(SOURCE_FILES
        "Source/MyCrossPlatformClass.hpp"
        "Source/MyCrossPlatformClass.cpp"
        "Source/Test.hpp"
        "Source/Test.cpp")

if(ANDROID)
    list(APPEND SOURCE_FILES
            "Source/Android/MyCrossPlatformClass.cpp"
            "Source/Android/MyCrossPlatformClass2.hpp"
            "Source/Android/MyCrossPlatformClass2.cpp"
            "Source/Android/Test.cpp"
            "Source/Android/Utilities/JniHelpers.hpp")
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
elseif(IOS)
    set(RESOURCE_FILES
            "Source/iOS/Resources/Main.storyboard")
    list(APPEND SOURCE_FILES
            "Source/iOS/MyCrossPlatformClass.mm"
            "Source/iOS/MyCrossPlatformDelegate.hpp"
            "Source/iOS/MyCrossPlatformDelegate.mm"
            "Source/iOS/Utilities/AppDelegate.hpp"
            "Source/iOS/Utilities/AppDelegate.mm"
            "Source/iOS/Utilities/main.mm"
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
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/Source/iOS/Resources/Info.plist")
elseif(APPLE)
    set(RESOURCE_FILES
            "Source/macOS/Resources/Main.storyboard")
    list(APPEND SOURCE_FILES
            "Source/macOS/MyCrossPlatformClass.mm"
            "Source/macOS/MyCrossPlatformDelegate.hpp"
            "Source/macOS/MyCrossPlatformDelegate.mm"
            "Source/macOS/Utilities/AppDelegate.hpp"
            "Source/macOS/Utilities/AppDelegate.mm"
            "Source/macOS/Utilities/main.mm"
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
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/Source/macOS/Resources/Info.plist")
elseif(WIN32)
    list(APPEND SOURCE_FILES
            "Source/Windows/MyCrossPlatformClass.cpp"
            "Source/Windows/Utilities/main.cpp")

    # Sort sources alphabetically
    list(SORT SOURCE_FILES)
    # Keep sources grouped by file system folders
    source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCE_FILES})

    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
else()
    message(FATAL_ERROR "Unknown target platform")
endif()
