int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh; //min heap decalration

    for (int i = 0; i < nums.size(); i++)
    {
        minh.push(nums[i]);
        if (minh.size() > k)
            minh.pop(); //O(nlogk)
    }
    return minh.top();
}