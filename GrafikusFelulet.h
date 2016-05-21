#ifndef GRAFIKUSFELULET_H
#define GRAFIKUSFELULET_H

#include "Widget.h"
#include "NumberControl.h"
#include <vector>



class GrafikusFelulet
{
    protected:
    private:
        std::vector<Widget*> widgets;
//        Button *b1;
//        Button *b2;
//        Button *b3;
    public:
        GrafikusFelulet(std::vector<std::vector<int>> & szamok);
        virtual ~GrafikusFelulet();
        void felrajzol(genv::event ev);
};

#endif // GRAFIKUSFELULET_H
