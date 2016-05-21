#include "NumberControl.h"
#include <sstream>
#include <string>
using namespace genv;

std::string szam_to_string(int szam){
    std::stringstream ss;
    ss <<szam;
    return ss.str();
}

//-------------------------------------------------------------------
NumberControl::NumberControl(int x0, int y0, int min0, int max0, int szam0): Widget(x0, y0),
                            min(min0), max(max0), szam(szam0) {
    t1 = new EditText(x,y,szam_to_string(szam));
    b1 = new Button(x+21, y, "plusz");
    b2 = new Button(x+21, y+12, "minusz");
    b1->eztcsinalja([&](){if(szam != max) ++szam;});
    b2->eztcsinalja([&](){if(szam != min) --szam;});
}
NumberControl::~NumberControl(){
    delete t1;
    delete b1;
    delete b2;
}

//-------------------------------------------------------------------
bool NumberControl::contains(int posx, int posy){
    return (t1->contains(posx,posy) || b1->contains(posx,posy) || b2->contains(posx,posy));
}

void NumberControl::handle(genv::event ev){
    Widget::handle(ev);
    if(ev.type == ev_mouse){
        t1->handle(ev); if(focused) t1->keepFocused();

        b1->handle(ev);
        b2->handle(ev);
        t1->setText(szam_to_string(szam));
    }
    if(focused  && ev.type == ev_key){
        if (ev.keycode == key_up && szam != max) {++szam;}
        else if (ev.keycode == key_down && szam != min) {--szam;}
        else if (ev.keycode == key_pgup && szam != max) {szam += 3; if(szam>max) szam=max;}
        else if (ev.keycode == key_pgdn && szam != min) {szam -= 3; if(szam<min) szam=min;}
        else if (ev.keycode == key_end) {szam=max;}
        else if (ev.keycode == key_home) {szam=min;}
        else if (ev.keycode == key_delete) {szam=min;}

        else if(ev.keycode > 47 && ev.keycode < 59){
            szam = ev.keycode - 48;
        }

        t1->setText(szam_to_string(szam));
    }
}

//-------------------------------------------------------------------
void NumberControl::draw(){
    t1->draw();
    if(folottevan){
        b1->draw();
        b2->draw();
    }
}

void NumberControl::fajlbair(std::ostream &file) {
    t1->fajlbair(file);
}

