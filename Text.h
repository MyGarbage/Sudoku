#ifndef TEXT_H
#define TEXT_H

#include "Widget.h"
#include <string>

class Text : public Widget
{
    protected:
        std::string label;
        int sx;
        int sy;
    public:
        Text(int x0, int y0, std::string label_0);
        virtual ~Text();
        virtual void draw();
        virtual bool contains(int posx, int posy);
        virtual void handle(genv::event ev);
        void keepFocused(){focused = true;};
        void setText(std::string szoveg);
        virtual void fajlbair(std::ostream &file);
};

#endif // TEXT_H
