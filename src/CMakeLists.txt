set(SOURCES
        player.cpp player.h
        axe.cpp axe.h
        collisional.cpp collisional.h)

add_library(sources_lib ${SOURCES})
add_executable(axe_game main.cpp)
target_link_libraries(axe_game
        sources_lib
        raylib)
