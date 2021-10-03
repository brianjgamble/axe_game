#include "input_handler.h"
#include "move_left_command.h"
#include "move_right_command.h"
#include <raylib.h>

InputHandler::InputHandler(int width)
{
    moveLeft  = new MoveLeftCommand{0};
    moveRight = new MoveRightCommand{width};
}

InputHandler::~InputHandler()
{
    delete moveLeft;
    delete moveRight;
}

Command* InputHandler::handleInput()
{
    if (IsKeyDown(KEY_A))
        return moveLeft;
    else if (IsKeyDown(KEY_D))
        return moveRight;
    else
        return nullptr;
}
