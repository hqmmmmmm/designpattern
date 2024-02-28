#include <iostream>

using namespace std;


class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile() {}
};

class SheepSmile: public AbstractSmile
{
public:
    void transform()
    {
        cout << "SheepSmile transform" << endl;
    }
    void ability()
    {
        cout << "SheepSmile ability" << endl;
    }
};

class LionSmile: public AbstractSmile
{
public:
    void transform() 
    {
        cout << "LionSmile transform" << endl;
    }
    void ability() 
    {
        cout << "LionSmile ability" << endl;
    }
};

class BatSmile: public AbstractSmile
{
public:
    void transform() 
    {
        cout << "BatSmile transform" << endl;
    }
    void ability() 
    {
        cout << "BatSmile ability" << endl;
    }
};


enum  ex
{
    ERROR, WARN, INFO
};

int main()
{
    ex e = ERROR;
    cout << e << endl;


    return 0;
}