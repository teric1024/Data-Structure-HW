/*
 Briefly explain the purpose and functionality of this file (program).

 @author Tu hao wei
 @ID     B06505001
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/
#include <iostream>
using namespace std;

//check if the input number is a prime
bool is_prime(int n)
{
    bool flag = true;
    for(int i = 2; i * i <= n; i += 1)
    {
        if(n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}


/*input a integer p
if it is prime then return it
if it is not a prime then return the nearest prime numbers both smaller and larger than p
*/
int* showPrime(int p)
{
    static int ans[2]={};
    if(is_prime(p))
    {
        ans[0] = p;
    }
    else
    {
        int i = p;
        while(!is_prime(i))
        {
            i -= 1;
        }
        ans[0] = i;
        i = p;
        while(!is_prime(i))
        {
            i += 1;
        }
        ans[1] = i;
    }
    return ans;
}

/*int main()
{
    int x = 0, *ans;
    cin >> x;
    ans = showPrime(x);
    cout << ans[0] << "  " << ans[1];
    return 0;
}*/
