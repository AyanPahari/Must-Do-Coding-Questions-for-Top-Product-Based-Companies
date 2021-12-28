#include <bits/stdc++.h>
using namespace std;
vector<int> prime;

void sieve(int maxN)
{
    vector<int> arr(maxN + 1, 0); //0 means prime
    arr[1] = 1;                   //1 means composite

    for (int i = 2; i * i <= maxN; i++)
        if (arr[i] == 0)
        {
            for (int j = i * i; j <= maxN; j += i)
                arr[j] = 1;
        }

    for (int i = 2; i <= maxN; i++)
    {
        if (arr[i] == 0)
        {
            prime.push_back(i);
        }
    }
}

void init(int L, int R)
{
    if (L == 1)
        L++; //1 cannot be prime so incrementing it to 2

    int maxN = R - L + 1;
    vector<int> arr(maxN, 0); //0 means prime

    for (auto p : prime) //for each prime number in prime array
        if (p * p <= R)  //if prime is less than or equal to sqrt R
        {
            int i = (L / p) * p; //to get the prime multiple
            if (i < L)
                i += p; //to get the prime multiple greater than L

            for (; i <= R; i += p)
            {
                if (i != p) //if i is not equal to the prime number itself
                    arr[i - L] = 1;
            }
        }

    for (int i = 0; i < maxN; i++)
        if (arr[i] == 0) //printing the prime numbers in the range
            cout << L + i << endl;
}

int main()
{
    sieve(100000); //to generate all the primes upto 10^5
    int t, L, R;
    cin >> t;

    while (t--)
    {
        cin >> L >> R;
        init(L, R);
        cout << endl;
    }
}

//problem on segmented sieve
//link: https://www.spoj.com/problems/PRIME1/