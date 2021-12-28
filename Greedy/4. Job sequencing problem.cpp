// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.

    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    //time: avg case-O(nlogn)
    //time: worst case-O(nlogn)
    //space: O(n)
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);

        int profit = 0, count = 0;
        bool temp[n] = {0};

        for (int i = 0; i < n; i++)
        {
            for (int j = min(arr[i].dead - 1, n); j >= 0; j--)
            { //min(..) is used because the value of
                //deadline could be larget than n. in that case we will get seg fault.
                if (temp[j] == 0)
                {
                    temp[j] = 1;
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {count, profit};
    }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends