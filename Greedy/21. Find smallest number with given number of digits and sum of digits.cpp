// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int count_sumofdigits(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    //time:O(D*10^(D-1))
    //space:O(1)
    int smallestNumber(int S, int D)
    {
        int start = pow(10, D - 1);
        int end = pow(10, D) - 1;
        //the range of the numbers is from 10^(D-1) and 10^D-1, where D is the number of digits
        int temp;
        int mini = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            temp = count_sumofdigits(i); //this func will return the sum of digits of the number i
            if (temp == S)
                mini = min(mini, i);
        }
        if (mini == INT_MAX) //if no number sum to S
            return -1;
        else
            return mini;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S, D) << endl;
    }
    return 0;
} // } Driver Code Ends