// Example program
#include <iostream>
#include <string>

using namespace std;

static int Result;

class India
{
    public:
    void Change(int x = 10, int y = 20, int z = 30)
    {
        cout<< x + y + z;
    }
    void Display(int x = 40, float y = 50.00)
    {
        Result = x % x; 
        cout<< Result;
    }
};

class CuriousTab1
{
    int x, y; 
    public:
    void Change(int x, int y = 50)
    {
        cout<< x + y;
    }
};

class CuriousTab: public India, public CuriousTab1
{
    public:
    void Display(int x = 10, int xx = 100, int xxx = 1000)
    {
        Result = x + xx % x * x;
        cout<< Result ; 
    }
};

int main()
{
    CuriousTab objCuriousTab;
    objCuriousTab.India::Display(10, 20.00);
    return 0; 
}