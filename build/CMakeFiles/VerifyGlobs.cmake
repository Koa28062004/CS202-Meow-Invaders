# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.27
cmake_policy(SET CMP0009 NEW)

# HEADERS at CMakeLists.txt:8 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/Users/macbookair/Desktop/CS202-Meow-Invaders/include/*.hpp include/*.h")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/macbookair/Desktop/CS202-Meow-Invaders/build/CMakeFiles/cmake.verify_globs")
endif()

# SOURCES at CMakeLists.txt:7 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/Users/macbookair/Desktop/CS202-Meow-Invaders/src/*.cpp")
set(OLD_GLOB
  "/Users/macbookair/Desktop/CS202-Meow-Invaders/src/Application.cpp"
  "/Users/macbookair/Desktop/CS202-Meow-Invaders/src/Entities/Entity.cpp"
  "/Users/macbookair/Desktop/CS202-Meow-Invaders/src/Entities/Player.cpp"
  "/Users/macbookair/Desktop/CS202-Meow-Invaders/src/GUI/Button.cpp"
  "/Users/macbookair/Desktop/CS202-Meow-Invaders/src/States/GameState.cpp"
  "/Users/macbookair/Desktop/CS202-Meow-Invaders/src/States/State.cpp"
  "/Users/macbookair/Desktop/CS202-Meow-Invaders/src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/macbookair/Desktop/CS202-Meow-Invaders/build/CMakeFiles/cmake.verify_globs")
endif()
