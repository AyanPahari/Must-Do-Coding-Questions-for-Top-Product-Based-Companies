// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{

    //time:O(nlogn)
    //space:O(1)
public:
    //Function to get the maximum total value in the knapsack.

    static bool comp(Item I1, Item I2)
    {
        double t1 = (double)I1.value / I1.weight;
        double t2 = (double)I2.value / I2.weight;

        return t1 > t2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        double profit = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= W)
            {
                profit += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                profit += (double)arr[i].value / arr[i].weight * W;
                break;
            }
        }
        return profit;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends