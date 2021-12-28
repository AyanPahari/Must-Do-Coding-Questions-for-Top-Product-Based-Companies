#include <bits/stdc++.h>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int x, y;
    cout << "Gcd: " << extended_gcd(a, b, x, y) << endl;

    cout << "x: " << x << "\n"
         << "y: " << y;

    return 0;
}

//to solve equations of the form ax+by=gcd(a,b), where the value of a and b is given and we have to find the gcd and the value of x and y.