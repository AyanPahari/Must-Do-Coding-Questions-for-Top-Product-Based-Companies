#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to merge the arrays.
    //using extra space
    //time:O(m+n)
    //space:O(m+n)
    void merge(long long nums1[], long long nums2[], int n, int m)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        long long res[m + n];

        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                res[k++] = nums1[i++];
            }
            else if (nums1[i] > nums2[j])
            {
                res[k++] = nums2[j++];
            }
            else
            {
                res[k++] = nums1[i++];
                res[k++] = nums2[j++];
            }
        }
        while (i < n)
        {
            res[k++] = nums1[i++];
        }
        while (j < m)
        {
            res[k++] = nums2[j++];
        }
        int ind = 0;
        while (ind < n)
        {
            nums1[ind] = res[ind];
            ind++;
        }
        int r = 0;
        while (ind < n + m)
        {
            nums2[r++] = res[ind++];
        }
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to merge the arrays.

    //without extra space(gap method or shell sort)
    //time:O((m+n)log(m+n))
    //space: O(1)

    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i, j;
        int gap = ceil((n + m) / 2.0);
        while (gap > 0)
        {
            i = 0;
            j = gap;
            while (j < n + m)
            {
                if (j < n)
                {
                    //checking between 1st array only
                    if (arr1[i] > arr1[j])
                    {
                        swap(arr1[i], arr1[j]);
                    }
                }
                else if (j >= n && i < n)
                {
                    //checking between 1st and the 2nd array
                    if (arr1[i] > arr2[j - n])
                    {
                        swap(arr1[i], arr2[j - n]);
                    }
                }
                else if (j >= n && i >= n)
                {
                    //checking between 2nd array only
                    if (arr2[i - n] > arr2[j - n])
                    {
                        swap(arr2[i - n], arr2[j - n]);
                    }
                }
                i++;
                j++;
            }
            if (gap != 1)
                gap = ceil(gap / 2.0);
            else
                gap /= 2;
        }
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends