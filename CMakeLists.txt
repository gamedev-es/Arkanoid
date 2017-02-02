#https://github.com/SFML/SFML/wiki/Tutorial:-Build-your-SFML-project-with-CMake
cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_NAME "Arkanoid")

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

set (CMAKE_CXX_STANDARD 11)

project(${EXECUTABLE_NAME})

# Set Variables and SDKs Folders
set(SRC_PATH ${CMAKE_SOURCE_DIR}/Source)
set(SDK_PATH ${CMAKE_SOURCE_DIR}/External)
set(BIN_PATH ${CMAKE_SOURCE_DIR}/Build)
set(SFML_ROOT ${SDK_PATH}/SFML)
#set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_PATH})
set(CMAKE_MODULE_PATH "${SDK_PATH}/cmake_modules" ${CMAKE_MODULE_PATH})

# Sources
set (SourceGroup_Game
	"${SRC_PATH}/Game/Arkanoid.h"
  "${SRC_PATH}/Game/Arkanoid.cpp"
  "${SRC_PATH}/Game/Ball.h"
  "${SRC_PATH}/Game/Ball.cpp"
  "${SRC_PATH}/Game/Paddle.h"
  "${SRC_PATH}/Game/Paddle.cpp"
  "${SRC_PATH}/Game/TestScene.h"
  "${SRC_PATH}/Game/TestScene.cpp"
)
source_group("Game" FILES ${SourceGroup_Game})

set (SourceGroup_GDCore
	"${SRC_PATH}/GDCore/Entity.h"
  "${SRC_PATH}/GDCore/Entity.cpp"
  "${SRC_PATH}/GDCore/GDCore.h"
  "${SRC_PATH}/GDCore/GDCore.cpp"
  "${SRC_PATH}/GDCore/Scene.h"
  "${SRC_PATH}/GDCore/Scene.cpp"
  "${SRC_PATH}/GDCore/SceneManager.h"
  "${SRC_PATH}/GDCore/SceneManager.cpp"
  "${SRC_PATH}/GDCore/InputManager.h"
  "${SRC_PATH}/GDCore/InputManager.cpp"
  "${SRC_PATH}/GDCore/ActionManager.h"
  "${SRC_PATH}/GDCore/ActionManager.cpp"
)
source_group("GDCore" FILES ${SourceGroup_GDCore})

set (SourceGroup_Main
	"${SRC_PATH}/main.cpp"
)
source_group("Main" FILES ${SourceGroup_Main})

set (SOURCE_FILES
  ${SourceGroup_Game}
  ${SourceGroup_GDCore}
	${SourceGroup_Main}
)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

# Detect and add SFML
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDECIES})
endif()

# Copying shared libraries
if (WIN32)
  ADD_CUSTOM_COMMAND (TARGET ${EXECUTABLE_NAME} POST_BUILD

    # DEBUG
    #if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-audio-d-2.dll ${BIN_PATH}/Debug
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-graphics-d-2.dll ${BIN_PATH}/Debug
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-network-d-2.dll ${BIN_PATH}/Debug
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-system-d-2.dll ${BIN_PATH}/Debug
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-window-d-2.dll ${BIN_PATH}/Debug
    #endif (CMAKE_BUILD_TYPE EQUAL "DEBUG")

    # RELEASE
    #if (CMAKE_BUILD_TYPE EQUAL "RELEASE")
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-audio-2.dll ${BIN_PATH}/Release
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-graphics-2.dll ${BIN_PATH}/Release
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-network-2.dll ${BIN_PATH}/Release
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-system-2.dll ${BIN_PATH}/Release
      COMMAND ${CMAKE_COMMAND} -E copy ${SFML_ROOT}/Library_Windows/sfml-window-2.dll ${BIN_PATH}/Release
    #endif (CMAKE_BUILD_TYPE EQUAL "RELEASE")

    # Output Message
    COMMENT "Copying SFML libraries" VERBATIM
  )
endif(WIN32)
