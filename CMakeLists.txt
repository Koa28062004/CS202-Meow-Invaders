cmake_minimum_required(VERSION 3.0)
project(cs202)

set(CMAKE_CXX_STANDARD 11)

# Defining the source files and includes
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.hpp include/*.h")

if (APPLE)
    set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.0")
endif()

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# Set the built executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# Adding the source files to the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-network)

target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})

# Adding the include directory
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Adding the external directory
target_include_directories(${PROJECT_NAME} PUBLIC external)