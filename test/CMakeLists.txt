set(TEST_SOURCES
        user_tests.cpp)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests
        Catch2::Catch2WithMain
        sources_lib)