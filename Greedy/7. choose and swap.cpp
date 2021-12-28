// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string chooseandswap(string a)
    {
        set<char> s;
        for (auto it : a)
            s.insert(it);

        char temp1, temp2;
        for (int i = 0; i < a.length(); i++)
        {
            s.erase(a[i]);
            if (s.empty())
                break;
            if (a[i] > *s.begin())
            {
                temp1 = a[i];
                temp2 = *s.begin();
                break;
            }
        }
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == temp1)
                a[i] = temp2;
            else if (a[i] == temp2)
                a[i] = temp1;
        }
        return a;
    }
};

// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}
// } Driver Code Ends