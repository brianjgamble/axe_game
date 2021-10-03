#ifndef AXE_GAME_PROJECT_INPUT_HANDLER_H
#define AXE_GAME_PROJECT_INPUT_HANDLER_H

#include "command.h"

class InputHandler {
public:
    explicit InputHandler(int width);
    ~InputHandler();

    Command* handleInput();

private:
    Command* moveLeft;
    Command* moveRight;
};

#endif
