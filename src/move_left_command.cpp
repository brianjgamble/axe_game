#include "move_left_command.h"

void MoveLeftCommand::execute(Component& component)
{
    if (component.isRightOf(boundary)) {
        component.moveLeft(10);
    }
}
