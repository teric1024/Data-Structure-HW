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
    bool flag = false;
    for(int i = 2; i * i <= n; i += 1)
    {
        if(n % i == 0)
        {
            flag = true;
            break;
        }
    }
    return flag;
}


/*input a integer p
if it is prime then return it
if it is not a prime then return the nearest prime numbers both smaller and larger than p*/
int[] showPrime(int p)
{
    if(is_prime(p))
    {

    }
    else
    {

    }
}

/*int main()
{
    int x = 0;
    cin >> x;
    cout << showPrime(x);
    return 0;
}*/
