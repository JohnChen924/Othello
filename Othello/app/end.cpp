#include "end.hpp"

void end::execute(EditorModel& model)
{
    undocolumn = model.cursorColumn();
    model.columnse(false);
}
void end::undo(EditorModel& model)
{
    model.undodown(undocolumn);
}