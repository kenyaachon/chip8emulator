# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/moses/.local/lib/python2.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/moses/.local/lib/python2.7/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/moses/Documents/chip8emulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moses/Documents/chip8emulator

# Include any dependencies generated for this target.
include CMakeFiles/chip8.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chip8.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chip8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chip8.dir/flags.make

CMakeFiles/chip8.dir/Source/Chip8.cpp.o: CMakeFiles/chip8.dir/flags.make
CMakeFiles/chip8.dir/Source/Chip8.cpp.o: Source/Chip8.cpp
CMakeFiles/chip8.dir/Source/Chip8.cpp.o: CMakeFiles/chip8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moses/Documents/chip8emulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chip8.dir/Source/Chip8.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chip8.dir/Source/Chip8.cpp.o -MF CMakeFiles/chip8.dir/Source/Chip8.cpp.o.d -o CMakeFiles/chip8.dir/Source/Chip8.cpp.o -c /home/moses/Documents/chip8emulator/Source/Chip8.cpp

CMakeFiles/chip8.dir/Source/Chip8.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chip8.dir/Source/Chip8.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moses/Documents/chip8emulator/Source/Chip8.cpp > CMakeFiles/chip8.dir/Source/Chip8.cpp.i

CMakeFiles/chip8.dir/Source/Chip8.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chip8.dir/Source/Chip8.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moses/Documents/chip8emulator/Source/Chip8.cpp -o CMakeFiles/chip8.dir/Source/Chip8.cpp.s

CMakeFiles/chip8.dir/Source/Main.cpp.o: CMakeFiles/chip8.dir/flags.make
CMakeFiles/chip8.dir/Source/Main.cpp.o: Source/Main.cpp
CMakeFiles/chip8.dir/Source/Main.cpp.o: CMakeFiles/chip8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moses/Documents/chip8emulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chip8.dir/Source/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chip8.dir/Source/Main.cpp.o -MF CMakeFiles/chip8.dir/Source/Main.cpp.o.d -o CMakeFiles/chip8.dir/Source/Main.cpp.o -c /home/moses/Documents/chip8emulator/Source/Main.cpp

CMakeFiles/chip8.dir/Source/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chip8.dir/Source/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moses/Documents/chip8emulator/Source/Main.cpp > CMakeFiles/chip8.dir/Source/Main.cpp.i

CMakeFiles/chip8.dir/Source/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chip8.dir/Source/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moses/Documents/chip8emulator/Source/Main.cpp -o CMakeFiles/chip8.dir/Source/Main.cpp.s

CMakeFiles/chip8.dir/Source/Platform.cpp.o: CMakeFiles/chip8.dir/flags.make
CMakeFiles/chip8.dir/Source/Platform.cpp.o: Source/Platform.cpp
CMakeFiles/chip8.dir/Source/Platform.cpp.o: CMakeFiles/chip8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moses/Documents/chip8emulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chip8.dir/Source/Platform.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chip8.dir/Source/Platform.cpp.o -MF CMakeFiles/chip8.dir/Source/Platform.cpp.o.d -o CMakeFiles/chip8.dir/Source/Platform.cpp.o -c /home/moses/Documents/chip8emulator/Source/Platform.cpp

CMakeFiles/chip8.dir/Source/Platform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chip8.dir/Source/Platform.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moses/Documents/chip8emulator/Source/Platform.cpp > CMakeFiles/chip8.dir/Source/Platform.cpp.i

CMakeFiles/chip8.dir/Source/Platform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chip8.dir/Source/Platform.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moses/Documents/chip8emulator/Source/Platform.cpp -o CMakeFiles/chip8.dir/Source/Platform.cpp.s

CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o: CMakeFiles/chip8.dir/flags.make
CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o: Source/Chip8instruct.cpp
CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o: CMakeFiles/chip8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moses/Documents/chip8emulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o -MF CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o.d -o CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o -c /home/moses/Documents/chip8emulator/Source/Chip8instruct.cpp

CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moses/Documents/chip8emulator/Source/Chip8instruct.cpp > CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.i

CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moses/Documents/chip8emulator/Source/Chip8instruct.cpp -o CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.s

# Object files for target chip8
chip8_OBJECTS = \
"CMakeFiles/chip8.dir/Source/Chip8.cpp.o" \
"CMakeFiles/chip8.dir/Source/Main.cpp.o" \
"CMakeFiles/chip8.dir/Source/Platform.cpp.o" \
"CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o"

# External object files for target chip8
chip8_EXTERNAL_OBJECTS =

chip8: CMakeFiles/chip8.dir/Source/Chip8.cpp.o
chip8: CMakeFiles/chip8.dir/Source/Main.cpp.o
chip8: CMakeFiles/chip8.dir/Source/Platform.cpp.o
chip8: CMakeFiles/chip8.dir/Source/Chip8instruct.cpp.o
chip8: CMakeFiles/chip8.dir/build.make
chip8: /usr/lib/x86_64-linux-gnu/libSDL2.so
chip8: CMakeFiles/chip8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moses/Documents/chip8emulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable chip8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chip8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chip8.dir/build: chip8
.PHONY : CMakeFiles/chip8.dir/build

CMakeFiles/chip8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chip8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chip8.dir/clean

CMakeFiles/chip8.dir/depend:
	cd /home/moses/Documents/chip8emulator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moses/Documents/chip8emulator /home/moses/Documents/chip8emulator /home/moses/Documents/chip8emulator /home/moses/Documents/chip8emulator /home/moses/Documents/chip8emulator/CMakeFiles/chip8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chip8.dir/depend

