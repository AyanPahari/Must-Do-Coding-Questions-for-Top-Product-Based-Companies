#include <iostream>
using namespace std;

int power(int a, int n, int m)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = (a * a) % m;
            n /= 2;
        }
        else
        {
            res = (res * a) % m;
            n--;
        }
    }
    return res % m;
}
int main()
{
    int a, m;
    cin >> a >> m;
    cout << "a^-1 = " << power(a, m - 2, m);
    return 0;
}
//here the value of a and m must be coprime i.e Gcd(a,m)=1
//Program to calculate the modulo inverse using Fermat's little theorem in time O(logm)