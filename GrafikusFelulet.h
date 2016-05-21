#ifndef GRAFIKUSFELULET_H
#define GRAFIKUSFELULET_H

#include "Widget.h"
#include <vector>



class GrafikusFelulet
{
    protected:
    private:
        std::vector<Widget*> widgets;
    public:
        GrafikusFelulet();
        virtual ~GrafikusFelulet();
        void felrajzol(genv::event ev);
};

#endif // GRAFIKUSFELULET_H
