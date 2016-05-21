#include "GrafikusFelulet.h"
#include "graphics.hpp"
#include "NumberControl.h"
using namespace genv;
#include <iostream>

extern const int XX,YY;

void kepernyottorol(){
    gout <<move_to(0,0) <<color(255,255,255) << box(XX,YY);
}

GrafikusFelulet::GrafikusFelulet(){

    for (int i=0; i<9; i++){
        for(int j=0; j<9; j++){
               NumberControl *nc = new NumberControl(50+i*43,50+j*30,0,9,0);
               widgets.push_back(nc);
        }
    }

}
GrafikusFelulet::~GrafikusFelulet(){
    for(Widget *w: widgets){
        delete w;
    }
}

//---------------------------------------

void GrafikusFelulet::felrajzol(event ev){

        kepernyottorol();
        for(Widget *w: widgets){
            w->draw();
            w->handle(ev);
        }
        //racs
        gout <<color(0,0,0)
             <<move_to(50,135) <<box(380,3) <<move_to(50,225) <<box(380,3)
             <<move_to(174,50) <<box(3,263) <<move_to(303,50) <<box(3,263);


}


