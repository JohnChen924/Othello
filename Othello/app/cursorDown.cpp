#include "cursorDown.hpp"

void cursorDown::execute(EditorModel& model)
{
    undodown = model.cursorColumn();
    model.setrow(true);
}
void cursorDown::undo(EditorModel& model)
{
    model.undodown(undodown);
    model.setrow(false);
}