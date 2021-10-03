#ifndef AXE_GAME_PROJECT_MOVE_RIGHT_COMMAND_H
#define AXE_GAME_PROJECT_MOVE_RIGHT_COMMAND_H

#include "command.h"

class MoveRightCommand : public Command {
public:
    explicit MoveRightCommand(int boundary) :
        boundary{boundary} {}
    void execute(Component& component) override;

private:
    int boundary;
};

#endif
