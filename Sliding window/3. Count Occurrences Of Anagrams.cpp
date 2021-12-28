int search(string pat, string txt)
{
    unordered_map<char, int> mp;
    int K = pat.length();
    for (int i = 0; i < K; i++)
    {
        mp[pat[i]]++;
    }
    int N = txt.length();
    int i = 0;
    int j = 0;
    int res = 0;
    int count = mp.size();
    while (j < N)
    {

        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;

            if (mp[txt[j]] == 0)
            {
                count--;
            }
        }

        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {

            if (count == 0)
            {
                res++;
            }

            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++;

                if (mp[txt[i]] == 1)
                {
                    count++;
                }
            }

            i++;
            j++;
        }
    }
    return res;
}