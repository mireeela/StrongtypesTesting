# Auto-discover test files

add_library(my_lib INTERFACE
)

target_include_directories(my_lib
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

