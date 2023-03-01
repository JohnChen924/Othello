#ifndef END_HPP
#define END_HPP

#include "Command.hpp"

class end : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    unsigned int undocolumn;
};

#endif