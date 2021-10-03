set(TEST_SOURCES
        player_tests.cpp
        axe_tests.cpp
        component_test.cpp)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests
        Catch2::Catch2WithMain
        sources_lib)

add_test(
        NAME UnitTests
        COMMAND tests
)