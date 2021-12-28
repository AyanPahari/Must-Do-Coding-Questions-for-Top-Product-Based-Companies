// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    //naive approach
    //time:O(n^2)
    //space:O(1)

    int celebrity(vector<vector<int>> &arr, int n)
    {
        int index = -1;
        int count_dist = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 0)
                    count++;
            }
            if (count == n)
            {
                index = i;
                count_dist++;
            }
        }
        int count_row = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != index && arr[i][index] == 1)
                count_row++;
        }
        if (count_row != n - 1)
            index = -1;

        if (count_dist > 1)
            return -1;
        else
            return index;
    }
};

//better approach using stack
//time:O(n)
//space:O(n)

int celebrity(vector<vector<int>> &arr, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);
    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if (arr[i][j] == 1)
            s.push(j);
        else if (arr[j][i] == 1)
            s.push(i);
    }
    if (s.size() == 0)
        return -1;
    int index = s.top();
    //now to check index's row and col
    int count_row = 0;
    for (int i = 0; i < n; i++)
    { //for row
        if (arr[index][i] == 0)
            count_row++;
    }
    int count_col = 0;
    for (int i = 0; i < n; i++)
    { //for col
        if (i != index && arr[i][index] == 1)
            count_col++;
    }
    if (count_row == n && count_col == n - 1)
        return index;
    else
        return -1;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends