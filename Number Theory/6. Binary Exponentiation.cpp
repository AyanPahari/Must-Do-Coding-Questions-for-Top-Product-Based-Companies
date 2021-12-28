#include <iostream>
using namespace std;

int power(int base, int n)
{
    static int res = 1;
    if (n == 0)
    {
        return res;
    }
    if (n % 2 == 0)
    {
        return power(base * base, n / 2); //recursive
    }
    else if (n % 2 != 0)
    {
        res = res * base;
        return power(base, n - 1);
    }
    return res;
}

int power(int base, int n)
{
    int res = 1;

    while (n)
    {
        if (n % 2 == 0)
        {
            base *= base;
            n /= 2; //iterative
        }
        else if (n % 2 != 0)
        {
            res = res * base;
            n--;
        }
    }
    return res;
}

int main()
{
    cout << power(3, 4);

    return 0;
}
