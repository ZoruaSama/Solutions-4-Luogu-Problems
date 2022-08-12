cmake_minimum_required(VERSION 3.16)
project(ChineseChessZorua)

set(CMAKE_CXX_STANDARD 41)
#add_executable(ChineseChessZorua main.cpp)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # include build directory where the qt generated header exists

# tell cmake where your qt5 library lies
set(Qt5_DIR D:/Qt/Qt5.12.10/5.12.10/mingw73_64/lib/cmake/Qt5)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

set(project_ui_files mainwindow.ui)
set(project_src_files main.cpp mainwindow.cpp)
set(project_header_files mainwindow.h Boardgame.cpp Boardgame.h Chess.cpp Chess.h)

set(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)

qt5_wrap_ui(project_headers_wrapped ${project_ui_files}) # ui files are converted to header files at build time like XML in WPF
qt5_wrap_cpp(project_src_moc ${project_header_files}) # because header files are where Q_Object is defined

add_executable(${PROJECT_NAME}  # ui files are not necessary here
        ${project_src_files}
        ${project_header_files}
        ${project_headers_wrapped}
        ${project_src_moc}
        )

target_link_libraries(${PROJECT_NAME} # PROJECT_NAME is case-sensitive
        PUBLIC
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )
