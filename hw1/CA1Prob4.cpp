/*
 Briefly explain the purpose and functionality of this file (program).

 @author Tu hao wei
 @ID     B06505001
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/
#include <iostream>
using namespace std;

class flower
{
private:
    string name;
    int petal;
    double price;
public:
// Constructor.
    flower (string n, int pt, double pr)
    {
        name = n; petal = pt; price = pr;
    };
// Set the name of the flower.
    void setName (string n)
    {
        name = n;
    };
// Set the petal number of the flower.
    void setPetal (int pt)
    {
        petal = pt;
    };
// Set the price of the flower.
    void setPrice (double pr)
    {
        price = pr;
    };
// Return the name of the flower.
    string getName ()
    {
        return name;
    };
// Return the petal number of the flower.
    int getPetal ()
    {
        return petal;
    };
// Return the price of the flower.
    double getPrice ()
    {
        return price;
    };
};
/*
int main()
{
    flower a("Nodding Trillium", 3, 75.0);
    a.setName("asdvas");
    cout << a.getName();
    return 0;
}
*/
