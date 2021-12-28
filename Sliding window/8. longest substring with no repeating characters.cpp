int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int i = 0;
    int j = 0;
    int mx = 0;
    unordered_map<char, int> mp;

    while (j < n)
    {
        mp[s[j]]++;

        if (mp.size() == j - i + 1)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if (mp.size() == j - i + 1)
            {
                mx = max(mx, j - i + 1);
            }
            j++;
        }
    }
    return mx;
}