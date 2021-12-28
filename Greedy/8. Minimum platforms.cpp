// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.

    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }

    //better approach
    //time:O(nlogn)
    //space:O(n)
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int, int>> tup;
        //for the 2nd val in pair...1-arrival and 0-departure
        for (int i = 0; i < n; i++)
        {
            tup.push_back({arr[i], 1});
            tup.push_back({dep[i], 0});
        }
        sort(tup.begin(), tup.end(), comp);

        int platforms = 0, count = 0;
        for (auto it : tup)
        {
            if (it.second == 1)
            {
                count++;
                platforms = max(platforms, count);
            }
            else
                count--;
        }
        return platforms;
    }
};

//optimised approach
//time:O(nlogn)
//space:O(1)

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms = 0, count = 1;
    int i = 1, j = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            platforms = max(platforms, count);
            i++;
        }
        else
        {
            count--;
            j++;
        }
    }
    return platforms;
}

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
} // } Driver Code Ends
