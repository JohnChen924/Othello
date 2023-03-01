#include "cursor.hpp"

void cursor::execute(EditorModel& model)
{
    model.setcolumn(true);
}
void cursor::undo(EditorModel& model)
{
    model.setcolumn(false);
}