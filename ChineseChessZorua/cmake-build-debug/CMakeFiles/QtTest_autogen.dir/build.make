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
CMAKE_SOURCE_DIR = C:\Users\Zorua\CLionProjects\ChineseChessZorua

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug

# Utility rule file for QtTest_autogen.

# Include the progress variables for this target.
include CMakeFiles/QtTest_autogen.dir/progress.make

CMakeFiles/QtTest_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target QtTest"
	D:\CLion\bin\cmake\win\bin\cmake.exe -E cmake_autogen C:/Users/Zorua/CLionProjects/ChineseChessZorua/cmake-build-debug/CMakeFiles/QtTest_autogen.dir/AutogenInfo.json Debug

QtTest_autogen: CMakeFiles/QtTest_autogen
QtTest_autogen: CMakeFiles/QtTest_autogen.dir/build.make

.PHONY : QtTest_autogen

# Rule to build all files generated by this target.
CMakeFiles/QtTest_autogen.dir/build: QtTest_autogen

.PHONY : CMakeFiles/QtTest_autogen.dir/build

CMakeFiles/QtTest_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\QtTest_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/QtTest_autogen.dir/clean

CMakeFiles/QtTest_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Zorua\CLionProjects\ChineseChessZorua C:\Users\Zorua\CLionProjects\ChineseChessZorua C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles\QtTest_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QtTest_autogen.dir/depend
