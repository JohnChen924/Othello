#include "KeypressInteractionReader.hpp"
#include "cursor.hpp"
#include "cursorLeft.hpp"
#include "cursorUp.hpp"
#include "cursorDown.hpp"
#include "home.hpp"
#include "Inputting.hpp"
#include "end.hpp"
#include "newl.hpp"
#include "deletel.hpp"
#include "backspace.hpp"

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {

            switch (keypress.code())
            {
            case 'O':
                return Interaction::command(new cursor);
            case 'U':
                return Interaction::command(new cursorLeft);
            case 'I':
                return Interaction::command(new cursorUp);
            case 'K':
                return Interaction::command(new cursorDown);
            case 'Y':
                return Interaction::command(new home);
            case 'P':
                return Interaction::command(new end);
            case 'J':
                return Interaction::command(new newl);
            case 'M':
                return Interaction::command(new newl);
            case 'D':
                return Interaction::command(new deletel);
            case 'H':
                return Interaction::command(new backspace);
            case 'Z':
                return Interaction::undo();
            case 'A':
                return Interaction::redo();
            case 'X':
                return Interaction::quit();
            }
        }
        else
        {
            return Interaction::command(new Inputting{keypress.code()});
        }
    }
}

