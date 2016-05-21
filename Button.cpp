#include "Button.h"
#include "graphics.hpp"
using namespace genv;

//-----------------------------------------------------------------------
Button::Button(int x0, int y0, std::string szoveg0): Widget(x0, y0),
               szoveg(szoveg0), csinalvalamit([](){}), levannyomva(0) {
    if (szoveg == "plusz" || szoveg == "minusz"){
        sx = 14;  sy = 11;}
    else {
        sx = gout.twidth(szoveg) + 6;
        sy = gout.cascent() + gout.cdescent() + 4;
    }
}
Button::~Button(){}

//-----------------------------------------------------------------------
bool Button::contains(int posx, int posy){
    return posx >= x && posx <= x+sx && posy >= y && posy <=y+sy;
}

void Button::eztcsinalja(std::function<void()> valami) {
    csinalvalamit = valami;
}

void Button::handle(event ev){
    Widget::handle(ev);
    if(ev.button == btn_left && folottevan){//contains(ev.pos_x, ev.pos_y)){
            csinalvalamit();
            levannyomva = true;
    }
    if (ev.button == -btn_left) levannyomva = false;
}

//------------------------------------------------------------------------
void Button::draw(){

    if (folottevan)  {
        if (levannyomva) gout <<color(100,100,100);
        else gout <<color(200,200,200);
        gout <<move_to(x,y) <<box(sx,sy);
    }
    else if (szoveg != "plusz" && szoveg != "minusz"){
        gout <<color(225,225,225) <<move_to(x,y) <<box(sx,sy);
    }

    //nyil vagy szoveg
    gout <<color(150,150,150);
    if(szoveg == "plusz"){
        for(int i=1; i<6; i++){
            gout <<move_to(x+7-i,y+3+i) <<line(2*i,0);
        }
    }
    else if (szoveg == "minusz"){
        for(int i=5; i>0; i--){
            gout <<move_to(x+7-i,y+7-i) <<line(2*i,0);
        }
    }
    else{
        gout <<move_to(x,y)
             <<line(sx,0) <<line(0,sy) <<line(-sx,0) <<line(0,-sy);

        gout <<move_to(x+3, y+3+gout.cascent())
             <<text(szoveg);
    }

}


