# Set C++ options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# CMake does not set DEBUG macro for debug builds
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
if(IOS)
	add_definitions(-D__IOS__ -D__APPLE__ -DTARGET_OS_IOS=1)
elseif(ANDROID)
	add_definitions(-D__ANDROID__)
elseif(APPLE)
	add_definitions(-D__APPLE__ -DTARGET_OS_OSX=1)
endif()
