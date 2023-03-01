

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"


void InteractionProcessor::run()
{
    view.refresh();
    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();
        if (interaction.type() == InteractionType::quit)
        {
            /*undo.clear();
            undo.shrink_to_fit();
            redo.clear();
            redo.shrink_to_fit();*/
            for(auto i = redo.begin();i!=redo.end();i++)
            {
                delete *i;
            }
            for(auto i = undo.begin();i!=undo.end();i++)
            {
                delete *i;
            }
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            try
            {
                
                if(undo.empty())
                {
                    EditorException e{"Nothing to Undo"};
                    throw e;
                }
                else
                {
                    Command* command = undo.back();
                    redo.push_back(command);
                    command->undo(model);
                    undo.pop_back();
                }
            }
            catch(EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }
            
            
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            try
            {
                if(redo.empty())
                {
                    EditorException e{"Nothing to redo"};
                    throw e;
                }
                else
                {
                    Command* command = redo.back();
                    undo.push_back(command);
                    command->execute(model);
                    redo.pop_back();
                }
            }
            catch(EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }
            
            
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();
            try
            {
                command->execute(model);
                redo.clear();
                undo.push_back(command);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                delete command;
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
        }
    }
}

