#ifndef DELETEL_HPP
#define DELETEL_HPP

#include "Command.hpp"
#include <string>

class deletel : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    std::string undostring;
    unsigned int undoline;
    unsigned int undoc;
};

#endif