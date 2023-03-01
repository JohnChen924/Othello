#ifndef NEWL_HPP
#define NEWL_HPP

#include "Command.hpp"
class newl : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    unsigned int undocolumn;
    unsigned int undorow;
};

#endif