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
CMAKE_SOURCE_DIR = C:\Users\Zorua\CLionProjects\AT1350

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Zorua\CLionProjects\AT1350\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AT1350.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AT1350.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AT1350.dir/flags.make

CMakeFiles/AT1350.dir/main.cpp.obj: CMakeFiles/AT1350.dir/flags.make
CMakeFiles/AT1350.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\AT1350\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AT1350.dir/main.cpp.obj"
	D:\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AT1350.dir\main.cpp.obj -c C:\Users\Zorua\CLionProjects\AT1350\main.cpp

CMakeFiles/AT1350.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AT1350.dir/main.cpp.i"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Zorua\CLionProjects\AT1350\main.cpp > CMakeFiles\AT1350.dir\main.cpp.i

CMakeFiles/AT1350.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AT1350.dir/main.cpp.s"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Zorua\CLionProjects\AT1350\main.cpp -o CMakeFiles\AT1350.dir\main.cpp.s

# Object files for target AT1350
AT1350_OBJECTS = \
"CMakeFiles/AT1350.dir/main.cpp.obj"

# External object files for target AT1350
AT1350_EXTERNAL_OBJECTS =

AT1350.exe: CMakeFiles/AT1350.dir/main.cpp.obj
AT1350.exe: CMakeFiles/AT1350.dir/build.make
AT1350.exe: CMakeFiles/AT1350.dir/linklibs.rsp
AT1350.exe: CMakeFiles/AT1350.dir/objects1.rsp
AT1350.exe: CMakeFiles/AT1350.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Zorua\CLionProjects\AT1350\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AT1350.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AT1350.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AT1350.dir/build: AT1350.exe

.PHONY : CMakeFiles/AT1350.dir/build

CMakeFiles/AT1350.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AT1350.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AT1350.dir/clean

CMakeFiles/AT1350.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Zorua\CLionProjects\AT1350 C:\Users\Zorua\CLionProjects\AT1350 C:\Users\Zorua\CLionProjects\AT1350\cmake-build-debug C:\Users\Zorua\CLionProjects\AT1350\cmake-build-debug C:\Users\Zorua\CLionProjects\AT1350\cmake-build-debug\CMakeFiles\AT1350.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AT1350.dir/depend

