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
int dotProduct(int a[], int b[], int n)
{
    int ans = 0;
    for(int i = 0; i < n; i += 1)
    {
        ans += a[i] * b[i];
    }
    return ans;
}

/*int main()
{
    int a[] = {-1, 0, 2, 15, 7, 6, -4, 8, 21, -13};
    int b[] = {5, 9, -18, 16, 0, 1, -4, 18, -2, 12};
    cout << dotProduct(a,b,3);
    return 0;
}*/
