set(TEST_SOURCES
        user_tests.cpp)

add_library(test_main STATIC test_main.cpp)
target_link_libraries(test_main Catch2::Catch2)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests
        test_main
        sources_lib)