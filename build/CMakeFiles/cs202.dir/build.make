# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macbookair/Desktop/CS202-Meow-Invaders

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbookair/Desktop/CS202-Meow-Invaders/build

# Include any dependencies generated for this target.
include CMakeFiles/cs202.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cs202.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cs202.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cs202.dir/flags.make

CMakeFiles/cs202.dir/src/GlobalVars.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/src/GlobalVars.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders/src/GlobalVars.cpp
CMakeFiles/cs202.dir/src/GlobalVars.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cs202.dir/src/GlobalVars.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/src/GlobalVars.cpp.o -MF CMakeFiles/cs202.dir/src/GlobalVars.cpp.o.d -o CMakeFiles/cs202.dir/src/GlobalVars.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders/src/GlobalVars.cpp

CMakeFiles/cs202.dir/src/GlobalVars.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/src/GlobalVars.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders/src/GlobalVars.cpp > CMakeFiles/cs202.dir/src/GlobalVars.cpp.i

CMakeFiles/cs202.dir/src/GlobalVars.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/src/GlobalVars.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders/src/GlobalVars.cpp -o CMakeFiles/cs202.dir/src/GlobalVars.cpp.s

CMakeFiles/cs202.dir/src/Menu.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/src/Menu.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders/src/Menu.cpp
CMakeFiles/cs202.dir/src/Menu.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cs202.dir/src/Menu.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/src/Menu.cpp.o -MF CMakeFiles/cs202.dir/src/Menu.cpp.o.d -o CMakeFiles/cs202.dir/src/Menu.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders/src/Menu.cpp

CMakeFiles/cs202.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/src/Menu.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders/src/Menu.cpp > CMakeFiles/cs202.dir/src/Menu.cpp.i

CMakeFiles/cs202.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/src/Menu.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders/src/Menu.cpp -o CMakeFiles/cs202.dir/src/Menu.cpp.s

CMakeFiles/cs202.dir/src/main.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/src/main.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders/src/main.cpp
CMakeFiles/cs202.dir/src/main.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cs202.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/src/main.cpp.o -MF CMakeFiles/cs202.dir/src/main.cpp.o.d -o CMakeFiles/cs202.dir/src/main.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders/src/main.cpp

CMakeFiles/cs202.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders/src/main.cpp > CMakeFiles/cs202.dir/src/main.cpp.i

CMakeFiles/cs202.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders/src/main.cpp -o CMakeFiles/cs202.dir/src/main.cpp.s

# Object files for target cs202
cs202_OBJECTS = \
"CMakeFiles/cs202.dir/src/GlobalVars.cpp.o" \
"CMakeFiles/cs202.dir/src/Menu.cpp.o" \
"CMakeFiles/cs202.dir/src/main.cpp.o"

# External object files for target cs202
cs202_EXTERNAL_OBJECTS =

/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: CMakeFiles/cs202.dir/src/GlobalVars.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: CMakeFiles/cs202.dir/src/Menu.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: CMakeFiles/cs202.dir/src/main.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: CMakeFiles/cs202.dir/build.make
/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: /opt/homebrew/lib/libsfml-graphics.2.6.0.dylib
/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: /opt/homebrew/lib/libsfml-window.2.6.0.dylib
/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: /opt/homebrew/lib/libsfml-network.2.6.0.dylib
/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: /opt/homebrew/lib/libsfml-system.2.6.0.dylib
/Users/macbookair/Desktop/CS202-Meow-Invaders/cs202: CMakeFiles/cs202.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable /Users/macbookair/Desktop/CS202-Meow-Invaders/cs202"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cs202.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cs202.dir/build: /Users/macbookair/Desktop/CS202-Meow-Invaders/cs202
.PHONY : CMakeFiles/cs202.dir/build

CMakeFiles/cs202.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cs202.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cs202.dir/clean

CMakeFiles/cs202.dir/depend:
	cd /Users/macbookair/Desktop/CS202-Meow-Invaders/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macbookair/Desktop/CS202-Meow-Invaders /Users/macbookair/Desktop/CS202-Meow-Invaders /Users/macbookair/Desktop/CS202-Meow-Invaders/build /Users/macbookair/Desktop/CS202-Meow-Invaders/build /Users/macbookair/Desktop/CS202-Meow-Invaders/build/CMakeFiles/cs202.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cs202.dir/depend

