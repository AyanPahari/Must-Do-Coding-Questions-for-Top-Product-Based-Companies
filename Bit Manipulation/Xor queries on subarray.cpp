class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {

        int n = arr.size();
        int prefix_array[n];
        prefix_array[0] = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            prefix_array[i] = prefix_array[i - 1] ^ arr[i];
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++)
        {
            int L = queries[i][0];
            int R = queries[i][1];

            if (L == 0)
            {
                result.push_back(prefix_array[R]);
            }
            else
            {
                result.push_back(prefix_array[R] ^ prefix_array[L - 1]);
            }
        }
        return result;
    }
};

/*
Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], 
for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
Return an array containing the result for the given queries.

link: https://leetcode.com/problems/xor-queries-of-a-subarray/

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
*/