set(SOURCES
        player.cpp player.h
        axe.cpp axe.h
        component.cpp component.h
        input_handler.cpp input_handler.h
        command.h
        move_left_command.cpp move_left_command.h
        move_right_command.cpp move_right_command.h)

add_library(sources_lib ${SOURCES})
target_link_libraries(sources_lib raylib)

add_executable(axe_game main.cpp)
target_link_libraries(axe_game sources_lib)
