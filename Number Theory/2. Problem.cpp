#include <iostream>
using namespace std;

bool fun(int N)
{
    if (N == 1)
    {
        return false;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
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
        int N;
        cin >> N;
        fun(N) ? cout << "yes" : cout << "no";
        cout << endl;
    }
    return 0;
}

//link: https://www.codechef.com/problems/PRB01