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
CMAKE_SOURCE_DIR = C:\Users\Zorua\CLionProjects\CF23B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Zorua\CLionProjects\CF23B\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CF23B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CF23B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CF23B.dir/flags.make

CMakeFiles/CF23B.dir/main.cpp.obj: CMakeFiles/CF23B.dir/flags.make
CMakeFiles/CF23B.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\CF23B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CF23B.dir/main.cpp.obj"
	D:\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CF23B.dir\main.cpp.obj -c C:\Users\Zorua\CLionProjects\CF23B\main.cpp

CMakeFiles/CF23B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CF23B.dir/main.cpp.i"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Zorua\CLionProjects\CF23B\main.cpp > CMakeFiles\CF23B.dir\main.cpp.i

CMakeFiles/CF23B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CF23B.dir/main.cpp.s"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Zorua\CLionProjects\CF23B\main.cpp -o CMakeFiles\CF23B.dir\main.cpp.s

# Object files for target CF23B
CF23B_OBJECTS = \
"CMakeFiles/CF23B.dir/main.cpp.obj"

# External object files for target CF23B
CF23B_EXTERNAL_OBJECTS =

CF23B.exe: CMakeFiles/CF23B.dir/main.cpp.obj
CF23B.exe: CMakeFiles/CF23B.dir/build.make
CF23B.exe: CMakeFiles/CF23B.dir/linklibs.rsp
CF23B.exe: CMakeFiles/CF23B.dir/objects1.rsp
CF23B.exe: CMakeFiles/CF23B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Zorua\CLionProjects\CF23B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CF23B.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CF23B.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CF23B.dir/build: CF23B.exe

.PHONY : CMakeFiles/CF23B.dir/build

CMakeFiles/CF23B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CF23B.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CF23B.dir/clean

CMakeFiles/CF23B.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Zorua\CLionProjects\CF23B C:\Users\Zorua\CLionProjects\CF23B C:\Users\Zorua\CLionProjects\CF23B\cmake-build-debug C:\Users\Zorua\CLionProjects\CF23B\cmake-build-debug C:\Users\Zorua\CLionProjects\CF23B\cmake-build-debug\CMakeFiles\CF23B.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CF23B.dir/depend

