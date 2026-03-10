# Auto-discover test files
file(GLOB TEST_SOURCES "*.cpp")

# Single test executable (adds all *.cpp in tests/)
add_executable(run_catch2_tests ${TEST_SOURCES})

target_link_libraries(run_catch2_tests
  PRIVATE
    my_lib
    Catch2::Catch2WithMain
)

target_include_directories(run_catch2_tests PRIVATE ${mdspan_SOURCE_DIR}/include)

# run these tests manually
add_test(NAME run_catch2_tests COMMAND $<TARGET_FILE:run_catch2_tests>)
