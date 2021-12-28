// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N); //sort the candies in ascending order

        int mini = 0, maxi = 0;
        int i = 0, j = N - 1;
        while (i <= j) //whenver they cross each other that means we have bought all the candies
        {
            mini += candies[i];
            i++;
            int temp = K;
            while (temp--) //as for each candy we get k more for free, so picking the max cost ones for free to reduce the cost
                j--;
        }
        i = 0, j = N - 1;
        while (i <= j)
        {
            maxi += candies[j];
            j--;
            int temp = K;
            while (temp--) //as for each candy we get k more for free, so picking the min cost ones for free to maximize the cost
                i++;
        }
        return {mini, maxi};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
} // } Driver Code Ends