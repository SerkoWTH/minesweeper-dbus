cmake_minimum_required(VERSION 3.5)

project(minesweeper LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(
    src-gen
    /home/serko/github/capicxx-core-runtime/include
    /home/serko/github/capicxx-dbus-runtime/include
    /home/serko/dbus-1.10.10
)
link_directories(
    /home/serko/github/capicxx-core-runtime/build
    /home/serko/github/capicxx-dbus-runtime/build
    /home/serko/dbus-1.10.10/dbus/.libs
)

add_executable(minesweeper-client
  src/main.cpp
  src/mainwindow.cpp
  src/mainwindow.h
  src/mainwindow.ui

  src-gen/v1/commonapi/minesweeperDBusProxy.cpp
  src-gen/v1/commonapi/minesweeperDBusDeployment
)

target_link_libraries(minesweeper-client PRIVATE Qt5::Widgets CommonAPI CommonAPI-DBus dbus-1)

add_executable(minesweeper-service
        src/minesweeperService.cpp
        src/minesweeperStubImpl.cpp
        src-gen/v1/commonapi/minesweeperDBusStubAdapter.cpp
        src-gen/v1/commonapi/minesweeperStubDefault
        src-gen/v1/commonapi/minesweeperDBusDeployment
)
target_link_libraries(minesweeper-service CommonAPI CommonAPI-DBus dbus-1)
