#include "cursorUp.hpp"

void cursorUp::execute(EditorModel& model)
{
    undoup = model.cursorColumn();
    model.setrow(false);
}
void cursorUp::undo(EditorModel& model)
{
    model.undodown(undoup);
    model.setrow(true);
}