#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>


class Application
{
    private:
        std::vector<std::vector<int>> szamok ;
        std::vector<std::vector<bool>> biztosszamok;
    protected:
    public:
        Application();
        virtual ~Application();
        void beolvas();
        void run();
};

#endif // APPLICATION_H
