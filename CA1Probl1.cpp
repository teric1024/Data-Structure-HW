/*
 Briefly explain the purpose and functionality of this file (program).

 @author Tu hao wei
 @ID     B06505001
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/

#include <iostream>
using namespace std;

//dot vector a and b
int dotProduct(int a[], int b[])
{
    int na = 0, nb = 0, ans = 0;
    na = sizeof(a) / sizeof(a[0]);
    nb = sizeof(b) / sizeof(b[0]);
    if(na != nb)
    {
        cout << "the lengths of two vectors are not same.";
        return -1;
    }
    for(int i = 0; i < na; i += 1)
    {
        ans += a[i] * b[i];
    }
    return ans;
}

/*int main()
{
    int a[] = {-1, 0, 2, 15, 7, 6, -4, 8, 21, -13};
    int b[] = {5, 9, -18, 16, 0, 1, -4, 18, -2, 12};
    cout << dotProduct(a,b);
    return 0;
}*/
