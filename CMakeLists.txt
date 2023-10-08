cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(PROJECT_MAJOR_VERSION 1)
set(PROJECT_MINOR_VERSION 0)
set(PROJECT_PATCH_VERSION 0)

include(cmake_utility/windowzify_linux_loader.cmake)

cmake_policy(SET CMP0100 NEW)

project(the_client_ui_showcase
  LANGUAGES CXX
  DESCRIPTION "the_client_ui_showcase"
  VERSION
    ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_VERSION}
)
set(project_name the_client_ui_showcase)

include(cmake_utility/organize_source_files.cmake)
include(cmake_utility/create_compiler_options.cmake)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
    ${source_files}
    ${public_header_files}
    ${private_header_files}
)
add_executable(meghdad::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include(cmake_utility/create_constants_options.cmake)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
)
target_compile_definitions(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_NAME}_VERSION="${PROJECT_VERSION}"
    ${PROJECT_NAME}_NAME="the_client_ui_showcase"
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Threads::Threads
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    $<BUILD_INTERFACE:${private_headers_dir}>
    $<BUILD_INTERFACE:${generated_private_headers_dir}>

  PUBLIC
    $<BUILD_INTERFACE:${generated_public_headers_dir}>
    $<BUILD_INTERFACE:${public_headers_dir}>
    $<INSTALL_INTERFACE:${public_headers_install_dir}>
    $<INSTALL_INTERFACE:${private_headers_install_dir}>
)

include(cmake_utility/configure_installation.cmake)
