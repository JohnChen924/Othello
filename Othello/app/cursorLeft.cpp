#include "cursorLeft.hpp"

void cursorLeft::execute(EditorModel& model)
{
    model.setcolumn(false);
}
void cursorLeft::undo(EditorModel& model)
{
    model.setcolumn(true);
}