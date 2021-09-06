add_library(test_main STATIC test_main.cpp)
target_link_libraries(test_main Catch2::Catch2)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE test_main)