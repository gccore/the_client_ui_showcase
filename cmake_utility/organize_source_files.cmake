set(project_with_version_name ${PROJECT_NAME}-${PROJECT_VERSION})

option(option_install_private_headers
  "Do you want to define an install role for the private headers?" off)

set(headers_dir ${PROJECT_SOURCE_DIR}/include)
set(public_headers_dir ${headers_dir}/public)
set(private_headers_dir ${headers_dir}/private)

file(GLOB source_files
  src/*.cc
)
file(GLOB public_header_files
  ${public_headers_dir}/${project_name}/*.hh
)
file(GLOB private_header_files
  ${private_headers_dir}/${project_name}/*.hh
)

source_group("Source Files"
  FILES
    ${source_files}
)
source_group("Public Headers"
  FILES
    ${public_header_files}
)
source_group("Private Headers"
  FILES
    ${private_header_files}
)


set(headers_install_dir include/${project_with_version_name})
set(public_headers_install_dir ${headers_install_dir}/public)
set(private_headers_install_dir ${headers_install_dir}/private)

set(generated_headers_dir
  ${PROJECT_BINARY_DIR}/include/${project_with_version_name})
set(generated_public_headers_dir ${generated_headers_dir}/public)
set(generated_private_headers_dir ${generated_headers_dir}/private)