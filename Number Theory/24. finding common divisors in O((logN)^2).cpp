#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            v1.push_back(make_pair(i, cnt));
        }
    }
    if (n > 1)
    {
        v1.push_back(make_pair(n, 1));
    }

    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;

        vector<pair<int, int>> v2;

        for (int i = 0; i < v1.size(); i++)
        {
            int cnt = 0;
            while (k % (v1[i].first) == 0)
            {
                cnt++;
                k /= (v1[i].first);
            }
            v2.push_back(make_pair((v1[i].first), cnt));
        }

        vector<pair<int, int>> v3;

        int i = 0;

        while (i < v1.size())
        {
            v3.push_back(make_pair((v1[i].first), min(v1[i].second, v2[i].second)));
            i++;
        }
        int finprod = 1;
        int j = 0;
        while (j < v1.size())
        {
            finprod *= ((v3[j].second) + 1);
            j++;
        }

        cout << finprod << "\n";
    }
    return 0;
}

//Given N, you have to answer Q queries, in each query you will be given a number K you have to find count of common divisors of N and K.
//complexity per query: O((logN)^2)