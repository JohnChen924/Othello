#include "Inputting.hpp"

void Inputting::execute(EditorModel& model)
{
    model.inputting(c);
}

void Inputting::undo(EditorModel& model)
{
    model.backspace();
}