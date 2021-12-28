#include <bits/stdc++.h>
using namespace std;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

cpp_int power(cpp_int base, cpp_int n, cpp_int mod)
{
    cpp_int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            base = ((base % mod) * (base % mod)) % mod;
            n /= 2;
        }
        else
        {
            res = ((res % mod) * (base % mod)) % mod;
            n--;
        }
    }
    return res;
}

bool fermat_primality(cpp_int n)
{
    int itr = 5; //number of iteration of checking to reduce the prob of error
    if (n == 2 || n == 3)
    {
        return true;
    }
    for (int i = 0; i < itr; i++)
    {
        cpp_int a = 2 + rand() % (n - 3); //a will range from 2 to p-2
        cpp_int res = power(a, n - 1, n); //calculating a^(p-1)
        if (res != 1)                     //if res!=1 then the number is defenitely composite, if res==1 then it could be either be prime or composite. chances of prime being very high
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cpp_int n;
        cin >> n;
        fermat_primality(n) ? cout << "YES" : cout << "NO";
        cout << endl;
    }
    return 0;
}

//here boost multiprecision library is used because when two 64 bit numbers are multiplied it will exceed the long long range.
//to avoid that cpp_int is used instead of long long

//link: https://www.spoj.com/problems/PON/