#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y) //extended euclidean algorithm
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x, int &y)
{
    int x0, y0;
    int g = gcd(abs(a), abs(b), x0, y0); //as a and b can be negative so passing the absoulte value
    if (c % g)                           //if c is not divisible by g then solution doesn't exist
    {
        return false;
    }

    x = x0 * c / g;
    y = y0 * c / g;
    if (a < 0) //if a is negative then simple transfering the negative sign to the variable
        x = -x;
    if (b < 0) //if b is negative then simple transfering the negative sign to the variable
        y = -y;
    return true;
}

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c;

    if (find_any_solution(a, b, c, x, y) == true)
    {
        cout << "Solution exists" << endl;
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }
    else
    {
        cout << "Solution does not exits" << endl;
    }

    return 0;
}
//This is the code for linear diophantine equation which will print only one of the possible values of x and y, given a,b and c for the equation ax+by=c