cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(QCustomPlot LANGUAGES CXX)

find_package(Threads REQUIRED)
find_package(QT
  NAMES Qt6 Qt5
  COMPONENTS
    Core
    Gui
    Widgets
    PrintSupport
  REQUIRED
)
find_package(Qt${QT_VERSION_MAJOR}
  COMPONENTS
    Core
    Gui
    Widgets
    PrintSupport
  REQUIRED
)

add_library(${PROJECT_NAME} SHARED qcustomplot.cpp qcustomplot.h)
add_library(QCustomPlot::QCustomPlot ALIAS ${PROJECT_NAME})
target_precompile_headers(${PROJECT_NAME}
  PUBLIC
    qcustomplot.h
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport

    Threads::Threads
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED true
    CXX_EXTENSIONS false

    C_STANDARD 17
    C_STANDARD_REQUIRED true
    C_EXTENSIONS false

    AUTOMOC true
    AUTOUIC true
    AUTORCC true
)