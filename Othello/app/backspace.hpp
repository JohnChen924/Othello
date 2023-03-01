#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"
class backspace : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    char undoc;
    unsigned int undocolumn;
};

#endif