# CppCrossPlatform

This is an example project for creating cross-platform apps with C++ for the article [in my blog](https://gusc.lv/2021/03/how-to-use-c-for-cross-platform-development/).

## Covered platforms

* Android
* iOS
* macOS
* Windows

## Covers techniques

* JNI
* Objective-C runtime

## Requirements

* [CMake](https://cmake.org/) 3.20+ for everything except Android, 3.10 shipped with Android SDK
* [Android Studio](https://developer.android.com/studio) for Android developemtn
* [Visual Studio](https://visualstudio.microsoft.com/) for Windows development (Community Edition will be enough)
* [Xcode](https://developer.apple.com/xcode/) for iOS and macOS development
* Gradle and Ninja are part of Android SDK

## Generating IDE projects

### Android Stuio

Just open the source root with Android Studio and hit Gradle Sync button on the top-right corner.

### Xcode

```bash
# Generate iOS project
cmake -G Xcode -S . -B build_ios -DCMAKE_SYSTEM_NAME=iOS
# Generate macOS project
cmake -G Xcode -S . -B build_macos
```

*note:* on iOS you'll need to set your devepoment team manually for code signing to work

### Visual Studio

```bash
# Generate Windows project
cmake -G "Visual Studio 15 2017 Win64" -S . -B build_windows
```
