#ifndef HOME_HPP
#define HOME_HPP

#include "Command.hpp"

class home : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    unsigned int undocolumn;
};

#endif