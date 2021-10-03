#include "move_right_command.h"

void MoveRightCommand::execute(Component& component)
{
    if (component.isLeftOf(boundary)) {
        component.moveRight(10);
    }
}
