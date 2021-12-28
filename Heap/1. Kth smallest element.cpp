int kthSmallest(int arr[], int l, int r, int k)
{
    //code here
    priority_queue<int> maxh; // max heap declaration

    for (int i = l; i <= r; i++)
    {
        maxh.push(arr[i]);
        if (maxh.size() > k)
        { //O(nlogk)
            maxh.pop();
        }
    }
    return maxh.top();
}