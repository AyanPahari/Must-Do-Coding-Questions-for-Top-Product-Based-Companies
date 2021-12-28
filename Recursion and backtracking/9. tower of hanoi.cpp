// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk.....
    void solve(int n, int source, int dest, int helper)
    {
        if (n == 1)
        {
            cout << "move disk 1 from rod " << source << " to rod " << dest;
            cout << endl;
            return;
        }
        solve(n - 1, source, helper, dest);
        cout << "move disk " << n << " from rod " << source << " to rod " << dest;
        cout << endl;
        solve(n - 1, helper, dest, source);
    }

    long long toh(int N, int from, int to, int aux)
    {
        solve(N, from, to, aux);
        int temp = pow(2, N) - 1;
        return temp;
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T; //testcases
    while (T--)
    {

        int N;
        cin >> N; //taking input N

        //calling toh() function
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}

//Position this line where user code will be pasted.  // } Driver Code Ends