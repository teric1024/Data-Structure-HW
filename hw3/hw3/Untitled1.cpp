#include <iostream>
using namespace std;

class P
{
protected:
    int a;
public:
    P(int in){a = in;}
    void Print(){cout << "P";}
    P* repointer(P &c){return &c;}
};

class C: public P
{
public:
    C(int in):P(in){};
    void Print(){cout << "C";}
    int geta(){return a;}

};

int main()
{
    P *p = new C(3);
    p->Print();
    cout << endl << static_cast<C*>(p)->geta() << endl;
    return 0;
}
