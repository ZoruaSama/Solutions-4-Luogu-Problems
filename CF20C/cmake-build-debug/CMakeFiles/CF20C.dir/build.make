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
CMAKE_SOURCE_DIR = C:\Users\Zorua\CLionProjects\CF20C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Zorua\CLionProjects\CF20C\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CF20C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CF20C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CF20C.dir/flags.make

CMakeFiles/CF20C.dir/main.cpp.obj: CMakeFiles/CF20C.dir/flags.make
CMakeFiles/CF20C.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\CF20C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CF20C.dir/main.cpp.obj"
	D:\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CF20C.dir\main.cpp.obj -c C:\Users\Zorua\CLionProjects\CF20C\main.cpp

CMakeFiles/CF20C.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CF20C.dir/main.cpp.i"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Zorua\CLionProjects\CF20C\main.cpp > CMakeFiles\CF20C.dir\main.cpp.i

CMakeFiles/CF20C.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CF20C.dir/main.cpp.s"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Zorua\CLionProjects\CF20C\main.cpp -o CMakeFiles\CF20C.dir\main.cpp.s

# Object files for target CF20C
CF20C_OBJECTS = \
"CMakeFiles/CF20C.dir/main.cpp.obj"

# External object files for target CF20C
CF20C_EXTERNAL_OBJECTS =

CF20C.exe: CMakeFiles/CF20C.dir/main.cpp.obj
CF20C.exe: CMakeFiles/CF20C.dir/build.make
CF20C.exe: CMakeFiles/CF20C.dir/linklibs.rsp
CF20C.exe: CMakeFiles/CF20C.dir/objects1.rsp
CF20C.exe: CMakeFiles/CF20C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Zorua\CLionProjects\CF20C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CF20C.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CF20C.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CF20C.dir/build: CF20C.exe

.PHONY : CMakeFiles/CF20C.dir/build

CMakeFiles/CF20C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CF20C.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CF20C.dir/clean

CMakeFiles/CF20C.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Zorua\CLionProjects\CF20C C:\Users\Zorua\CLionProjects\CF20C C:\Users\Zorua\CLionProjects\CF20C\cmake-build-debug C:\Users\Zorua\CLionProjects\CF20C\cmake-build-debug C:\Users\Zorua\CLionProjects\CF20C\cmake-build-debug\CMakeFiles\CF20C.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CF20C.dir/depend

