// { Driver Code Starts
//Initial Template for C++

// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Function to return the lexicographically sorted power-set of the string.

void solve(string input, string output, vector<string> &res)
{
    if (input.length() == 0)
    {
        res.push_back(output);
        return;
    }
    string output1 = output;
    string output2 = output;

    output2.push_back(input[0]);
    input.erase(input.begin() + 0);

    solve(input, output1, res);
    solve(input, output2, res);

    return;
}

vector<string> powerSet(string input)
{
    vector<string> res;
    string output = "";
    solve(input, output, res);
    sort(res.begin(), res.end());
    return res;
}

// { Driver Code Starts.

// Driver code
int main()
{
    int T;
    cin >> T; //testcases
    while (T--)
    {
        string s;
        cin >> s; //input string

        //calling powerSet() function
        vector<string> ans = powerSet(s);

        //sorting the result of the powerSet() function
        sort(ans.begin(), ans.end());

        //printing the result
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends