#include "deletel.hpp"

void deletel::execute(EditorModel& model)
{
    undostring = model.getline(model.cursorLine());
    undoline = model.cursorLine();
    undoc = model.cursorColumn();
    model.deleteline();
}
void deletel::undo(EditorModel& model)
{
    model.undodeleteline(undostring,undoline,undoc);
}