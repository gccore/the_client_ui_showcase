cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
cmake_policy(SET CMP0100 NEW)

project(the_client_ui_showcase LANGUAGES CXX)

find_package(Threads REQUIRED)
find_package(QT
  NAMES Qt6 Qt5
  COMPONENTS
    Core
    Widgets
  REQUIRED
)

add_executable(${PROJECT_NAME} main.cc)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/private/
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Threads::Threads

    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
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