# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\CLion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Zorua\CLionProjects\P2357

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Zorua\CLionProjects\P2357\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P2357.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P2357.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P2357.dir/flags.make

CMakeFiles/P2357.dir/main.cpp.obj: CMakeFiles/P2357.dir/flags.make
CMakeFiles/P2357.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\P2357\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P2357.dir/main.cpp.obj"
	D:\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\P2357.dir\main.cpp.obj -c C:\Users\Zorua\CLionProjects\P2357\main.cpp

CMakeFiles/P2357.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P2357.dir/main.cpp.i"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Zorua\CLionProjects\P2357\main.cpp > CMakeFiles\P2357.dir\main.cpp.i

CMakeFiles/P2357.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P2357.dir/main.cpp.s"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Zorua\CLionProjects\P2357\main.cpp -o CMakeFiles\P2357.dir\main.cpp.s

# Object files for target P2357
P2357_OBJECTS = \
"CMakeFiles/P2357.dir/main.cpp.obj"

# External object files for target P2357
P2357_EXTERNAL_OBJECTS =

P2357.exe: CMakeFiles/P2357.dir/main.cpp.obj
P2357.exe: CMakeFiles/P2357.dir/build.make
P2357.exe: CMakeFiles/P2357.dir/linklibs.rsp
P2357.exe: CMakeFiles/P2357.dir/objects1.rsp
P2357.exe: CMakeFiles/P2357.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Zorua\CLionProjects\P2357\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P2357.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\P2357.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P2357.dir/build: P2357.exe

.PHONY : CMakeFiles/P2357.dir/build

CMakeFiles/P2357.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\P2357.dir\cmake_clean.cmake
.PHONY : CMakeFiles/P2357.dir/clean

CMakeFiles/P2357.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Zorua\CLionProjects\P2357 C:\Users\Zorua\CLionProjects\P2357 C:\Users\Zorua\CLionProjects\P2357\cmake-build-debug C:\Users\Zorua\CLionProjects\P2357\cmake-build-debug C:\Users\Zorua\CLionProjects\P2357\cmake-build-debug\CMakeFiles\P2357.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P2357.dir/depend
