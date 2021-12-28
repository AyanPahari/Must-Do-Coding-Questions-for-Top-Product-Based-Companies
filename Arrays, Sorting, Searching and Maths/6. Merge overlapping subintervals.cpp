class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        
        sort(intervals.begin(),intervals.end());
        vector<int>temp;
        temp=intervals[0];
        for(auto it:intervals){
            if(temp[1]>=it[0]){
                temp[1]=max(temp[1],it[1]);
            }
            else{
                res.push_back(temp);
                temp=it;
            }
        }
        res.push_back(temp);
        return res;
    }
};