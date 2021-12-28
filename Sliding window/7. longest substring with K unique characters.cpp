int longestKSubstr(string s, int k)
{
    int i = 0;
    int j = 0;
    int mx = -1;
    int n = s.length();
    unordered_map<char, int> mp;

    while (j < n)
    {
        mp[s[j]]++;

        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;

                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if (mp.size() == k)
            {
                mx = max(mx, j - i + 1);
            }
            j++;
        }
    }
    return mx;
}