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
CMAKE_SOURCE_DIR = /Users/macbookair/Desktop/CS202-Meow-Invaders-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbookair/Desktop/CS202-Meow-Invaders-1/build

# Include any dependencies generated for this target.
include CMakeFiles/cs202.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cs202.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cs202.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cs202.dir/flags.make

CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Applications/Application.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Applications/Application.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Applications/Application.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Applications/Application.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Components/Movement.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Components/Movement.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Components/Movement.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Components/Movement.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Bullet.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Bullet.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Bullet.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Bullet.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Enemy.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Enemy.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Enemy.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Enemy.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/EnemyManager.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/EnemyManager.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/EnemyManager.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/EnemyManager.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Entity.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Entity.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Entity.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Entity.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Player.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Player.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Player.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/Entities/Player.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/GUI/Button.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/GUI/Button.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/GUI/Button.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/GUI/Button.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/GlobalVars/GlobalVars.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/GlobalVars/GlobalVars.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/GlobalVars/GlobalVars.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/GlobalVars/GlobalVars.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/GameState.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/GameState.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/GameState.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/GameState.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/MenuState.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/MenuState.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/MenuState.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/MenuState.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/PauseState.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/PauseState.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/PauseState.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/PauseState.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/State.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/State.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/State.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/States/State.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.s

CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o: CMakeFiles/cs202.dir/flags.make
CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/main.cpp
CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o: CMakeFiles/cs202.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o -MF CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o.d -o CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o -c /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/main.cpp

CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/main.cpp > CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.i

CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookair/Desktop/CS202-Meow-Invaders-1/MEOW_INVADERS/main.cpp -o CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.s

# Object files for target cs202
cs202_OBJECTS = \
"CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o" \
"CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o"

# External object files for target cs202
cs202_EXTERNAL_OBJECTS =

/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/Applications/Application.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/Components/Movement.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Bullet.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Enemy.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/EnemyManager.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Entity.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/Entities/Player.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/GUI/Button.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/GlobalVars/GlobalVars.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/States/GameState.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/States/MenuState.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/States/PauseState.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/States/State.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/MEOW_INVADERS/main.cpp.o
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/build.make
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: /opt/homebrew/lib/libsfml-graphics.2.6.0.dylib
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: /opt/homebrew/lib/libsfml-window.2.6.0.dylib
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: /opt/homebrew/lib/libsfml-network.2.6.0.dylib
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: /opt/homebrew/lib/libsfml-system.2.6.0.dylib
/Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202: CMakeFiles/cs202.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable /Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cs202.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cs202.dir/build: /Users/macbookair/Desktop/CS202-Meow-Invaders-1/cs202
.PHONY : CMakeFiles/cs202.dir/build

CMakeFiles/cs202.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cs202.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cs202.dir/clean

CMakeFiles/cs202.dir/depend:
	cd /Users/macbookair/Desktop/CS202-Meow-Invaders-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macbookair/Desktop/CS202-Meow-Invaders-1 /Users/macbookair/Desktop/CS202-Meow-Invaders-1 /Users/macbookair/Desktop/CS202-Meow-Invaders-1/build /Users/macbookair/Desktop/CS202-Meow-Invaders-1/build /Users/macbookair/Desktop/CS202-Meow-Invaders-1/build/CMakeFiles/cs202.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cs202.dir/depend

