#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output, vector<string> &res)
{
    if (input.length() == 0)
    {
        res.push_back(output);
        return;
    }
    string output1 = output;
    string output2 = output;

    output1.push_back(input[0]);
    output2.push_back(toupper(input[0]));

    input.erase(input.begin() + 0);

    solve(input, output1, res);
    solve(input, output2, res);

    return;
}

int main()
{
    string input;
    cin >> input;
    string output = "";
    vector<string> res;
    solve(input, output, res);

    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}
