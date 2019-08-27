cmake_minimum_required(VERSION 3.6)
project(Progress-master)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(test)


set(SOURCE_FILES
        main.cpp
        Observer.h
        Subject.h
        BarGUI.cpp
        BarGUI.h
        FileManager.cpp
        FileManager.h
        ResourceFile.cpp
        ResourceFile.h
        ProgressBarDisplay.cpp
        ProgressBarDisplay.h
        Display.h)

add_executable(Progress-master ${SOURCE_FILES} )
add_library(core ${SOURCE_FILES})

set(CURSES_NEED_NCURSES,TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})
target_link_libraries(Progress-master ${CURSES_LIBRARIES})


