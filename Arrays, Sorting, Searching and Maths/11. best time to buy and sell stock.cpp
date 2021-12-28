class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        /*
        //Brute force approach. Time Complexity O(n^2)
        int max_pro=0;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i;j<arr.size();j++){
                if(arr[j]>arr[i]) max_pro=max(max_pro,arr[j]-arr[i]);
            }
        }
        return max_pro;
        */

        //Optimal Approach
        //time: O(n)
        //space: O(1)
        int mini = INT_MAX;
        int max_pro = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < mini)
            {
                mini = arr[i];
            }
            max_pro = max(max_pro, arr[i] - mini);
        }
        return max_pro;
    }
};