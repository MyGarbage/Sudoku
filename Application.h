#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>


class Application
{
    protected:
        std::vector<std::vector<int>> szamok ;
    public:
        Application();
        virtual ~Application();
        void beolvas();
        void run();
};

#endif // APPLICATION_H
