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

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

ui_mainwindow.h: ../mainwindow.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_mainwindow.h"
	D:\Qt\Qt5.12.10\5.12.10\mingw73_64\bin\uic.exe -o C:/Users/Zorua/CLionProjects/ChineseChessZorua/cmake-build-debug/ui_mainwindow.h C:/Users/Zorua/CLionProjects/ChineseChessZorua/mainwindow.ui

moc_mainwindow.cpp: ../mainwindow.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating moc_mainwindow.cpp"
	D:\Qt\Qt5.12.10\5.12.10\mingw73_64\bin\moc.exe @C:/Users/Zorua/CLionProjects/ChineseChessZorua/cmake-build-debug/moc_mainwindow.cpp_parameters

CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.obj: CMakeFiles/untitled.dir/includes_CXX.rsp
CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.obj: untitled_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.obj"
	D:\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled.dir\untitled_autogen\mocs_compilation.cpp.obj -c C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\untitled_autogen\mocs_compilation.cpp

CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.i"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\untitled_autogen\mocs_compilation.cpp > CMakeFiles\untitled.dir\untitled_autogen\mocs_compilation.cpp.i

CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.s"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\untitled_autogen\mocs_compilation.cpp -o CMakeFiles\untitled.dir\untitled_autogen\mocs_compilation.cpp.s

CMakeFiles/untitled.dir/main.cpp.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/main.cpp.obj: CMakeFiles/untitled.dir/includes_CXX.rsp
CMakeFiles/untitled.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled.dir/main.cpp.obj"
	D:\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled.dir\main.cpp.obj -c C:\Users\Zorua\CLionProjects\ChineseChessZorua\main.cpp

CMakeFiles/untitled.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/main.cpp.i"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Zorua\CLionProjects\ChineseChessZorua\main.cpp > CMakeFiles\untitled.dir\main.cpp.i

CMakeFiles/untitled.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/main.cpp.s"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Zorua\CLionProjects\ChineseChessZorua\main.cpp -o CMakeFiles\untitled.dir\main.cpp.s

CMakeFiles/untitled.dir/mainwindow.cpp.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/mainwindow.cpp.obj: CMakeFiles/untitled.dir/includes_CXX.rsp
CMakeFiles/untitled.dir/mainwindow.cpp.obj: ../mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/untitled.dir/mainwindow.cpp.obj"
	D:\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled.dir\mainwindow.cpp.obj -c C:\Users\Zorua\CLionProjects\ChineseChessZorua\mainwindow.cpp

CMakeFiles/untitled.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/mainwindow.cpp.i"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Zorua\CLionProjects\ChineseChessZorua\mainwindow.cpp > CMakeFiles\untitled.dir\mainwindow.cpp.i

CMakeFiles/untitled.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/mainwindow.cpp.s"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Zorua\CLionProjects\ChineseChessZorua\mainwindow.cpp -o CMakeFiles\untitled.dir\mainwindow.cpp.s

CMakeFiles/untitled.dir/moc_mainwindow.cpp.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/moc_mainwindow.cpp.obj: CMakeFiles/untitled.dir/includes_CXX.rsp
CMakeFiles/untitled.dir/moc_mainwindow.cpp.obj: moc_mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/untitled.dir/moc_mainwindow.cpp.obj"
	D:\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled.dir\moc_mainwindow.cpp.obj -c C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\moc_mainwindow.cpp

CMakeFiles/untitled.dir/moc_mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/moc_mainwindow.cpp.i"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\moc_mainwindow.cpp > CMakeFiles\untitled.dir\moc_mainwindow.cpp.i

CMakeFiles/untitled.dir/moc_mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/moc_mainwindow.cpp.s"
	D:\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\moc_mainwindow.cpp -o CMakeFiles\untitled.dir\moc_mainwindow.cpp.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/untitled.dir/main.cpp.obj" \
"CMakeFiles/untitled.dir/mainwindow.cpp.obj" \
"CMakeFiles/untitled.dir/moc_mainwindow.cpp.obj"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled.exe: CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.obj
untitled.exe: CMakeFiles/untitled.dir/main.cpp.obj
untitled.exe: CMakeFiles/untitled.dir/mainwindow.cpp.obj
untitled.exe: CMakeFiles/untitled.dir/moc_mainwindow.cpp.obj
untitled.exe: CMakeFiles/untitled.dir/build.make
untitled.exe: D:/Qt/Qt5.12.10/5.12.10/mingw73_64/lib/libQt5Widgetsd.a
untitled.exe: D:/Qt/Qt5.12.10/5.12.10/mingw73_64/lib/libQt5Guid.a
untitled.exe: D:/Qt/Qt5.12.10/5.12.10/mingw73_64/lib/libQt5Cored.a
untitled.exe: CMakeFiles/untitled.dir/linklibs.rsp
untitled.exe: CMakeFiles/untitled.dir/objects1.rsp
untitled.exe: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable untitled.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled.exe

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend: ui_mainwindow.h
CMakeFiles/untitled.dir/depend: moc_mainwindow.cpp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Zorua\CLionProjects\ChineseChessZorua C:\Users\Zorua\CLionProjects\ChineseChessZorua C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug C:\Users\Zorua\CLionProjects\ChineseChessZorua\cmake-build-debug\CMakeFiles\untitled.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

