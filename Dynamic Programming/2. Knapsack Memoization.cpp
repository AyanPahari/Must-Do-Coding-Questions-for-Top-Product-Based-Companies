int t[1001][1001];

int Knapsack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (t[n - 1][W] != -1)
    {
        return t[n - 1][W];
    }
    else if (wt[n - 1] <= W)
    {
        return t[n - 1][W] = max(val[n - 1] + Knapsack(W - wt[n - 1], wt, val, n - 1), Knapsack(W, wt, val, n - 1));
    }
    else
    {
        return t[n - 1][W] = Knapsack(W, wt, val, n - 1);
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    memset(t, -1, sizeof(t));
    return Knapsack(W, wt, val, n);
}