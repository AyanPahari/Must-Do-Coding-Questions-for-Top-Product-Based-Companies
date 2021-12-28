#include <iostream>
using namespace std;

int Phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res /= i;
            res = res * (i - 1);

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        res /= n;
        res = res * (n - 1);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << Phi(n);

    return 0;
}
//this program finds euler's totient function in O(sqN) time.
//Phi(n)=n*(p1-1)*(p2-1)*(p3-1)*....*(pk-1)
//       ----------------------------------
//          p1*p2*p3*...............*pk


// where p1,p2 etc are the prime factorization of the number n.