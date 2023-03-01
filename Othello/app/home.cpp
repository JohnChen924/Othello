#include "home.hpp"

void home::execute(EditorModel& model)
{
    undocolumn = model.cursorColumn();
    model.columnse(true);
}
void home::undo(EditorModel& model)
{
    model.undodown(undocolumn);
}