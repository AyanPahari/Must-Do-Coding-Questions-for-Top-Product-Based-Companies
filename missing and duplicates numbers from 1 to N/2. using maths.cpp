int *findTwoElement(int *arr, int n)
{

    long long ideal_sum = (n * (n + 1)) / 2;
    long long ideal_prod = (n * (n + 1) * (2 * n + 1)) / 6;
    long long non_ideal_sum = 0;
    long long non_ideal_prod = 0;
    for (int i = 0; i < n; i++)
    {
        non_ideal_sum += arr[i];
        non_ideal_prod += arr[i] * arr[i];
    }

    long long diff1 = ideal_sum - non_ideal_sum;
    long long diff2 = ideal_prod - non_ideal_prod;

    long long diff = diff2 / diff1;

    long long a = (diff1 + diff) / 2;
    long long b = (diff - diff1) / 2;
    int *res = new int(2);
    res[0] = b;    // a is the missing number
                    // b is the duplicate number
    res[1] = a;
    return res;
}
// this method only works for one missing and one duplicate.
// O(n) time complexity
//O(1) space complexity