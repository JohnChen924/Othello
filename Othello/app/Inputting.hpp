#ifndef INPUTTING_HPP
#define INPUTTING_HPP

#include "Command.hpp"

class Inputting : public Command
{
public:
    Inputting(char c)
        : c{c}
    {
    }
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    char c;
};

#endif