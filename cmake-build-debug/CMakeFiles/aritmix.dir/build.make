# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /home/cleuton/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/cleuton/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cleuton/Documents/projetos/aritmix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cleuton/Documents/projetos/aritmix/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/aritmix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/aritmix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/aritmix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aritmix.dir/flags.make

CMakeFiles/aritmix.dir/aritmix.cpp.o: CMakeFiles/aritmix.dir/flags.make
CMakeFiles/aritmix.dir/aritmix.cpp.o: /home/cleuton/Documents/projetos/aritmix/aritmix.cpp
CMakeFiles/aritmix.dir/aritmix.cpp.o: CMakeFiles/aritmix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cleuton/Documents/projetos/aritmix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aritmix.dir/aritmix.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aritmix.dir/aritmix.cpp.o -MF CMakeFiles/aritmix.dir/aritmix.cpp.o.d -o CMakeFiles/aritmix.dir/aritmix.cpp.o -c /home/cleuton/Documents/projetos/aritmix/aritmix.cpp

CMakeFiles/aritmix.dir/aritmix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aritmix.dir/aritmix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cleuton/Documents/projetos/aritmix/aritmix.cpp > CMakeFiles/aritmix.dir/aritmix.cpp.i

CMakeFiles/aritmix.dir/aritmix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aritmix.dir/aritmix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cleuton/Documents/projetos/aritmix/aritmix.cpp -o CMakeFiles/aritmix.dir/aritmix.cpp.s

# Object files for target aritmix
aritmix_OBJECTS = \
"CMakeFiles/aritmix.dir/aritmix.cpp.o"

# External object files for target aritmix
aritmix_EXTERNAL_OBJECTS =

aritmix: CMakeFiles/aritmix.dir/aritmix.cpp.o
aritmix: CMakeFiles/aritmix.dir/build.make
aritmix: CMakeFiles/aritmix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/cleuton/Documents/projetos/aritmix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aritmix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aritmix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aritmix.dir/build: aritmix
.PHONY : CMakeFiles/aritmix.dir/build

CMakeFiles/aritmix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aritmix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aritmix.dir/clean

CMakeFiles/aritmix.dir/depend:
	cd /home/cleuton/Documents/projetos/aritmix/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cleuton/Documents/projetos/aritmix /home/cleuton/Documents/projetos/aritmix /home/cleuton/Documents/projetos/aritmix/cmake-build-debug /home/cleuton/Documents/projetos/aritmix/cmake-build-debug /home/cleuton/Documents/projetos/aritmix/cmake-build-debug/CMakeFiles/aritmix.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/aritmix.dir/depend

