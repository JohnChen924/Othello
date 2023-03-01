#include "backspace.hpp"

void backspace::execute(EditorModel& model)
{
    undocolumn = model.cursorColumn();
    model.backspace();
    undoc = model.getcharacter();
}
void backspace::undo(EditorModel& model)
{
    model.undobackspace(undocolumn,undoc);
}