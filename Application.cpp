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
    this->beolvas();
}
Application::~Application(){}


void Application::beolvas(){
    std::ifstream file;
    file.open("simple.txt");

    if (file.is_open()){
        for(int i=0; i<9; i++){
            for (int j=0; j<9;j++){
                file >>szamok[i][j];
            }
        }
        file.close();
    }
    else {
        std::cout <<"File is not open";
    }

}


//--------------------------------------------
void Application::run(){


    genv::gout.open(XX,YY);
    srand(time(nullptr));
    GrafikusFelulet graf(szamok);

    event ev;
    gin.timer(100);
    while(gin >> ev && ev.keycode != key_escape) {

        graf.felrajzol(ev);
        genv::gout << refresh;
    }

}
