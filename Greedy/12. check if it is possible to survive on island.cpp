// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        int total_food = S * M;
        int days = ceil((float)total_food / N);
        if (days > S) //if days required to purchase all the food from shop exceeds the duration of survival
            return -1;
        if (days > 6)
        {
            int actual_days_to_purchase = days + days / 7; //to compensate the days wasted in sundays
            if (actual_days_to_purchase > S)
                return -1;
            else
                return days;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;
    }
    return 0;
} // } Driver Code Ends