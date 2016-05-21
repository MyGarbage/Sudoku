#include "graphics.hpp"
#include "Application.h"
#include "GrafikusFelulet.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace genv;
#include <iostream>

extern groutput& gout;

extern const int XX = 600, YY = 500;


Application::Application(){
    beolvas();
    biztosszamok = std::vector<std::vector<bool>> (9, std::vector<bool> (9,false));
}
Application::~Application(){}


void Application::beolvas(){
    std::ifstream file;
    file.open("Simple.txt");

    for(int i=0; i<9; i++){
        for (int j=0; j<9;j++){
            file >>szamok[i][j];
            if (szamok[i][j] != 0) biztosszamok[i][j] = true;
        }
    }
    file.close();
}


//--------------------------------------------
void Application::run(){


    genv::gout.open(XX,YY);
    srand(time(nullptr));
    GrafikusFelulet graf;

    event ev;
    gin.timer(100);
    while(gin >> ev && ev.keycode != key_escape) {

        graf.felrajzol(ev);
        genv::gout << refresh;
    }

}
