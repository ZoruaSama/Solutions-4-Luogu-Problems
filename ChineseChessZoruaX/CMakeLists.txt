#cmake_minimum_required(VERSION 3.16)
#project(ChineseChessZorua)
#
#set(CMAKE_CXX_STANDARD 14)
##add_executable(ChineseChessZorua main.cpp)
#set(CMAKE_INCLUDE_CURRENT_DIR ON) # include build directory where the qt generated header exists
#
## tell cmake where your qt5 library lies
#set(Qt5_DIR D:/Qt/Qt5.12.10/5.12.10/mingw73_64/lib/cmake/Qt5)
#find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)
#
#set(project_ui_files mainwindow.ui)
#set(project_src_files main.cpp mainwindow.cpp)
#set(project_header_files mainwindow.h Boardgame.cpp Boardgame.h Chess.cpp Chess.h)
#
#set(CMAKE_AUTOMOC ON)
#SET(CMAKE_AUTOUIC ON)
#
#qt5_wrap_ui(project_headers_wrapped ${project_ui_files}) # ui files are converted to header files at build time like XML in WPF
#qt5_wrap_cpp(project_src_moc ${project_header_files}) # because header files are where Q_Object is defined
#
#add_executable(${PROJECT_NAME}  # ui files are not necessary here
#        ${project_src_files}
#        ${project_header_files}
#        ${project_headers_wrapped}
#        ${project_src_moc}
#        )
#
#target_link_libraries(${PROJECT_NAME} # PROJECT_NAME is case-sensitive
#        PUBLIC
#        Qt5::Core
#        Qt5::Widgets
#        Qt5::Gui
#        ws2_32
#        )

cmake_minimum_required(VERSION 3.16)
project(ChineseChessZorua)

set(CMAKE_CXX_STANDARD 14)
#add_executable(ChineseChessZorua main.cpp)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # include build directory where the qt generated header exists
# 设置Qt5的cmake模块所在目录，如果不设置将使用系统提供的版本
# QT_DIR和QT_VERSION是指定了qt安装目录和版本的环境变量
# 如果你使用了系统的cmake，那么会优先使用系统提供模块，因为cmake会优先搜索CMAKE_SYSTEM_PREFIX_PATH
# 如果你不想让cmake优先搜索系统目录（会导致编译使用系统安装的qt而不是我们配置的），需要提示find_package命令
# tell cmake where your qt5 library lies


set(Qt5_DIR D:/Qt/Qt5.12.10/5.12.10/mingw73_64/lib/cmake/Qt5)
#set(Qt5_DIR D:/Qt/Qt5.12.10/5.12.10/msvc2017_64/lib/cmake/Qt5)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Network)


#add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
#add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
set(project_ui_files mainwindow.ui)
set(project_src_files main.cpp mainwindow.cpp)
set(project_header_files mainwindow.h)

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
        Qt5::Network
#        wsock32
        ws2_32
        )