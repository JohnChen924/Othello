#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"

class cursorLeft : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif