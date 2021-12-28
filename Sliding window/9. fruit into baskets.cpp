// In a row of trees, the i - th tree produces fruit with type tree[i].

//     You start at any tree of your choice,
//     then repeatedly perform the following steps :

//     Add one piece of fruit from this tree to your baskets.If you cannot,
//     stop.Move to the next tree to the right of the current tree.
//     If there is no tree to the right, stop.
//     Note that you do not have any choice after the initial choice of starting tree :
//     you must perform step 1, then step 2,
//     then back to step 1, then step 2, and so on until you stop.

//     You have two baskets,and each basket can carry any quantity of fruit,
//     but you want each basket to only carry one type of fruit each.
//     What is the total amount of fruit you can collect with this procedure?

int totalFruit(vector<int> &tree)
{
    int n = tree.size();
    int i = 0;
    int j = 0;
    unordered_map<int, int> mp;
    int mx = 0;

    while (j < n)
    {
        mp[tree[j]]++;

        if (mp.size() <= 2)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (mp.size() > 2)
        {
            while (mp.size() > 2)
            {
                mp[tree[i]]--;

                if (mp[tree[i]] == 0)
                {
                    mp.erase(tree[i]);
                }
                i++;
            }
            if (mp.size() <= 2)
            {
                mx = max(mx, j - i + 1);
            }
            j++;
        }
    }
    return mx;
}