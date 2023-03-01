#include "newl.hpp"

void newl::execute(EditorModel& model)
{
    undocolumn = model.cursorColumn();
    undorow = model.cursorLine();
    model.newline();
}
void newl::undo(EditorModel& model)
{
    model.undonewline(undorow, undocolumn);
}