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
CMAKE_SOURCE_DIR = C:\Users\Zorua\CLionProjects\P1427

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Zorua\CLionProjects\P1427\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P1427.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P1427.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P1427.dir/flags.make

CMakeFiles/P1427.dir/main.c.obj: CMakeFiles/P1427.dir/flags.make
CMakeFiles/P1427.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\P1427\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/P1427.dir/main.c.obj"
	D:\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\P1427.dir\main.c.obj   -c C:\Users\Zorua\CLionProjects\P1427\main.c

CMakeFiles/P1427.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P1427.dir/main.c.i"
	D:\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Zorua\CLionProjects\P1427\main.c > CMakeFiles\P1427.dir\main.c.i

CMakeFiles/P1427.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P1427.dir/main.c.s"
	D:\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Zorua\CLionProjects\P1427\main.c -o CMakeFiles\P1427.dir\main.c.s

# Object files for target P1427
P1427_OBJECTS = \
"CMakeFiles/P1427.dir/main.c.obj"

# External object files for target P1427
P1427_EXTERNAL_OBJECTS =

P1427.exe: CMakeFiles/P1427.dir/main.c.obj
P1427.exe: CMakeFiles/P1427.dir/build.make
P1427.exe: CMakeFiles/P1427.dir/linklibs.rsp
P1427.exe: CMakeFiles/P1427.dir/objects1.rsp
P1427.exe: CMakeFiles/P1427.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Zorua\CLionProjects\P1427\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable P1427.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\P1427.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P1427.dir/build: P1427.exe

.PHONY : CMakeFiles/P1427.dir/build

CMakeFiles/P1427.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\P1427.dir\cmake_clean.cmake
.PHONY : CMakeFiles/P1427.dir/clean

CMakeFiles/P1427.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Zorua\CLionProjects\P1427 C:\Users\Zorua\CLionProjects\P1427 C:\Users\Zorua\CLionProjects\P1427\cmake-build-debug C:\Users\Zorua\CLionProjects\P1427\cmake-build-debug C:\Users\Zorua\CLionProjects\P1427\cmake-build-debug\CMakeFiles\P1427.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P1427.dir/depend

