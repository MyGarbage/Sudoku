#include "GrafikusFelulet.h"
#include "graphics.hpp"
//#include "NumberControl.h"
using namespace genv;
#include <iostream>

extern const int XX,YY;

void kepernyottorol(){
    gout <<move_to(0,0) <<color(255,255,255) << box(XX,YY);
}

GrafikusFelulet::GrafikusFelulet(std::vector<std::vector<int>> &szamok){

    for (int i=0; i<9; i++){
        for(int j=0; j<9; j++){
               NumberControl *nc = new NumberControl(50+i*43,50+j*30,0,9,szamok[i][j]);
               widgets.push_back(nc);
        }
    }
//    b1 = new Button(460,50,"Simple");
//    b2 = new Button(460,90,"Medium");
//    b3 = new Button(460,130,"Difficult");
//    b1->eztcsinalja([&](){});
//    b2->eztcsinalja([&](){});
//    b3->eztcsinalja([&](){});

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


