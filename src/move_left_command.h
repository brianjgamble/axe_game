#ifndef AXE_GAME_PROJECT_MOVE_LEFT_COMMAND_H
#define AXE_GAME_PROJECT_MOVE_LEFT_COMMAND_H

#include "command.h"

class MoveLeftCommand : public Command {
public:
    explicit MoveLeftCommand(int boundary) :
        boundary{boundary} {}
    void execute(Component& component) override;

private:
    int boundary;
};

#endif
