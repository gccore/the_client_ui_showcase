set(cmake_configs_dir lib/cmake/${project_with_version_name})

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Config
)
install(
  EXPORT ${PROJECT_NAME}Config
  NAMESPACE meghdad::
  DESTINATION ${cmake_configs_dir}
)
install(
  FILES
    ${public_header_files}
  DESTINATION ${public_headers_install_dir}/${PROJECT_NAME}
)

if(${option_install_private_headers})
  install(
    FILES
      ${private_header_files}
    DESTINATION ${private_headers_install_dir}/${PROJECT_NAME}
  )
endif()

include(CMakePackageConfigHelpers)

set(project_config_version_path
  ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
write_basic_package_version_file(
  ${project_config_version_path}
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)
install(
  FILES
    ${project_config_version_path}
  DESTINATION ${cmake_configs_dir}
)

get_target_property(target_type ${PROJECT_NAME} TYPE)
if (NOT target_type STREQUAL "EXECUTABLE")
  include(GenerateExportHeader)

  set(project_export_macro_path
    ${generated_public_headers_dir}/${project_name}/${project_name}_export.hh)
  generate_export_header(${PROJECT_NAME}
    EXPORT_FILE_NAME ${project_export_macro_path}
  )
  install(
    FILES
      ${project_export_macro_path}
    DESTINATION ${public_headers_install_dir}/${project_name}
  )
  list(APPEND public_header_files ${project_export_macro_path})
  target_sources(${PROJECT_NAME} PRIVATE ${project_export_macro_path})
endif ()


include(CPack)
