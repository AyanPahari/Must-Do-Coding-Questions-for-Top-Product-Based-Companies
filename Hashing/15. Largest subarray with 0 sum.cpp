int maxLen(int arr[], int n)
{
    //better approach 
    //time:O(n^2)
    //space:O(1)
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0, len = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            len++;
            if (sum == 0)
                ans = max(ans, len);
        }
    }
    return ans;
}

int maxLen(int arr[], int n)
{
    unordered_map<int, int> mp;
    int maxi = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
            maxi = max(maxi, i + 1);
        else if (mp.find(sum) != mp.end())
            maxi = max(maxi, i - mp[sum]);
        else
            mp[sum] = i;
    }
    return maxi;
}
