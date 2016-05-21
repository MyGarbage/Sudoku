#include "Widget.h"
using namespace genv;

Widget::Widget(int x0, int y0): x(x0), y(y0), focused(0), folottevan(0) {}
Widget::~Widget(){}

void Widget::handle(event ev){
    if(ev.type == ev_mouse){
            folottevan = contains(ev.pos_x, ev.pos_y);
            if (ev.button == btn_left)
                focused = folottevan;//contains(ev.pos_x,ev.pos_y);
    }
}

