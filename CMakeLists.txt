cmake_minimum_required(VERSION 3.2)
project(Arkanoid)

FILE(GLOB SRC "*.cpp" "*.h")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)

set(SOURCE_FILES Source/main.cpp)
add_executable(Arkanoid ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_PREFIX_PATH "External/SFML")
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Arkanoid ${SFML_LIBRARIES})
	
	#set_target_properties(SFML PROPERTIES
	#	BUILD_SHARED_LIBS 0
	#)
endif()