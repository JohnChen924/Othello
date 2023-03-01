#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "Command.hpp"

class cursor : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif