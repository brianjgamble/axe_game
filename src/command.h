#ifndef AXE_GAME_PROJECT_COMMAND_H
#define AXE_GAME_PROJECT_COMMAND_H

#include "component.h"

class Command {
public:
    virtual ~Command() = default;

    virtual void execute(Component& component) = 0;
};

#endif
