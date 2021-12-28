#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.size() == 0)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void reverse_stack(stack<int> &s)
{
    if (s.size() == 0 || s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    reverse_stack(s);
    insert(s, temp);
}

int main()
{
    int n, k;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        s.push(k);
    }
    reverse_stack(s);
    while (!s.empty())
    {
        int k = s.top();
        s.pop();
        cout << k << " ";
    }
    return 0;
}
