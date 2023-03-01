// EditorModel.cpp
//
// ICS 45C Fall 2021
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <string>

EditorModel::EditorModel()
    : row{1}, column{1}, linec{1}, error{""}, s{""}
{
    text.push_back("");
}


int EditorModel::cursorLine() const
{
    return row;
}


int EditorModel::cursorColumn() const
{
    return column;
}


int EditorModel::lineCount() const
{
    return linec;
}

void EditorModel::setcolumn(bool edit)
{
    char test;
    if(edit)
    {
        try
        {
            test = text[row-1].at(column-1);
            column++;
        }
        catch(const std::out_of_range& e)
        {
            EditorException error{"Edit of Line"};
            throw error;
        }
        
        
    }
    else
    {
        if(column == 1)
        {
            EditorException e{"Beginning of text."};
            throw e;
        }
        column--;
    }

}

void EditorModel::undodown(unsigned int down)
{
    column = down;
}
void EditorModel::setrow(bool edit)
{
    if(edit) //down
    {
        if(row == linec)
        {
            EditorException e{"Last line of text."};
            throw e;
        }
        if(text[row].size() < column)
        {
            column = text[row].size()+1;
        }
        else if(text[row] == "")
        {
            column = 1;
        }
        row++;
    }
    else //up
    {
        if(row == 1)
        {
            EditorException e{"First line of text."};
            throw e;
        }
        if(text[row-2].size() < column)
        {
            column = text[row-2].size()+1;
        }
        else if(text[row-2] == "")
        {
            column = 1;
        }
        row--;
    }
    
}

void EditorModel::columnse(bool edit)
{
    if(edit)
    {
        column = 1;
    }
    else
    {
        column = text[row-1].size()+1;
    }
}

void EditorModel::inputting(char c)
{
    text[row-1].insert(text[row-1].begin()+column-1, c);
    column++;
}

void EditorModel::newline()
{
    s = text[row-1].substr(column-1,text[row-1].size());
    text[row-1].erase(column-1,text[row-1].size());
    column = 1;
    row++;
    linec++;
    text.insert(text.begin()+ row-1,s); 
}

void EditorModel::undonewline(unsigned int r,unsigned int c)
{
    column = c;
    std::string s= text[row-2];
    text.erase(text.begin()+r-1);
    linec--;
    row--;
    text[row-1].insert(0,s);
}

std::string EditorModel::getline(unsigned int i)
{
    return text[i-1];
}

void EditorModel::undodeleteline(std::string txt, unsigned int r, unsigned int c)
{
    linec++;
    text.insert(text.begin()+r-1,txt);
    column = c;
    row = r;
}

void EditorModel::deleteline()
{
    if(linec > 1)
    {
        if(row<linec)
        {
                
            text.erase(text.begin()+row-1);
            linec--;
            if(column>text[row-1].size())
            {
                column = text[row-1].size()+1;
            }
        }
        else
        {
            linec--;
            row--;
            column = text[row-1].size()+1;
        }
        
    }
    else if(linec == 1)
    {
        text[row-1].clear();
        column = 1;
    }
}

void EditorModel::backspace()
{
    if(column == 1 and row == 1)
    {
        EditorException e{"Cannot backspace"};
        throw e;
    }
    else
    {
        if(column == 1)
        {
            if(column > 1)
            {
                undocharacter = text[row-2][column-2];
            }
            
            column = text[row-2].size()+1;
            text[row-2] += text[row-1];
            text[row-1] = "";
            row--;
            linec--;     
        }
        else
        {
            undocharacter = text[row-1][column-2];
            text[row-1].erase(text[row-1].begin()+column-2);
            column--;
        }
    }
}

void EditorModel::undobackspace(unsigned int undocolumn,char undoc)
{
    if(undocolumn == 1)
    {
        newline();
    }
    else
    {
        inputting(undoc);
    }
}

char EditorModel::getcharacter()
{
    return undocharacter;
}

const std::string& EditorModel::line(int lineNumber) const
{
    return text[lineNumber -1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return error;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    error = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    error = "";
}

