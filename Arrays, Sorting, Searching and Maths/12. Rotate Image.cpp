class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        /*
        //Brute force approach: using another 2D array 
        //time:O(n^2)
        //space:O(n^2)
        vector<vector<int>>copy(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                copy[j][n-i-1]=matrix[i][j];
            }
        }
        matrix=copy;
        */

        //optimal approach: first transpose and then reverse any row(for clockwise rotation)
        //optimal approach: first reverse and then transpose any row(for anti-clockwise rotation)
        //time:O(n^2)
        //space:O(1)

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};