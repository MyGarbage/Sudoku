#ifndef EDITTEXT_H
#define EDITTEXT_H

#include "Text.h"
#include <string>


class EditText : public Text
{
    private:
        int kurzor;
    protected:
    public:
        EditText(int x0, int y0, std::string label_0);
        virtual ~EditText();
        virtual void draw();
        virtual void handle(genv::event ev);
};

#endif // EDITTEXT_H
