#include <bits/stdc++.h>
using namespace std;

string smallestWindow(string s, string p)
{
    unordered_map<char, int> mp;
    int n = s.length();
    for (int i = 0; i < p.length(); i++)
    {
        mp[p[i]]++;
    }
    int i = 0;
    int j = 0;
    int count = mp.size();
    int mn = INT_MAX;
    int start = 0;
    int end = 0;

    while (j < n)
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;

            if (mp[s[j]] == 0)
            {
                count--;
            }
        }
        if (count == 0)
        {
            if (j - i + 1 < mn)
            {
                mn = j - i + 1;
                start = i;
                end = j;
            }
            while (count == 0)
            {
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;

                    if (mp[s[i]] == 1)
                    {
                        count++;
                    }
                    i++;
                }
                else
                {
                    i++;
                }
            }
            if (j - i + 2 < mn)
            {
                mn = j - i + 2;
                start = i - 1;
                end = j;
            }
        }
        j++;
    }
    string str;
    if (mn == INT_MAX)
    {
        return str;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            str.push_back(s[i]);
        }
    }
    return str;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << smallestWindow(str1, str2);
    return 0;
}
