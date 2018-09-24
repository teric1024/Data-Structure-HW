/*
 Briefly explain the purpose and functionality of this file (program).

 @author Tu hao wei
 @ID     B06505001
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/

#include <iostream>
using namespace std;
/*
check if n is a multiple of m
*/
bool isMultiple(long n, long m)
{
    if(n % m == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*int main()
{
    int a = 7, b = 8;
    cout << a % b;
    return 0;
}*/
