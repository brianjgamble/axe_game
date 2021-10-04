#include "input_handler.h"
#include "move_left_command.h"
#include "move_right_command.h"
#include <raylib.h>

namespace {
    bool keyLeft()
    {
        return IsKeyDown(KEY_A);
    }
    bool keyRight()
    {
        return IsKeyDown(KEY_D);
    }
    bool gamePadLeft()
    {
        return IsGamepadAvailable(0) && IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
    }
    bool gamePadRight()
    {
        return IsGamepadAvailable(0) && IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
    }
}

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
    if (keyLeft() || gamePadLeft())
        return moveLeft;
    else if (keyRight() || gamePadRight())
        return moveRight;
    else
        return nullptr;
}