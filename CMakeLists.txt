cmake_minimum_required(VERSION 2.6)

project(arkanoid)

include_directories(include)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(arkanoid ${SRC_FILES})

find_package(SFML 2 REQUIRED system window graphics)
if(NOT SFML_FOUND)
	message(FATAL_ERROR "Install SFML library.")
endif()

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(arkanoid ${SFML_LIBRARIES})
