class CustomStack
{
public:
    vector<int> arr;
    int maxi;

    CustomStack(int maxSize)
    {
        maxi = maxSize;
    }

    void push(int x)
    {
        if (arr.size() < maxi)
            arr.push_back(x);
    }

    int pop()
    {
        if (arr.size() == 0)
            return -1;
        else
        {
            int x = arr.back();
            arr.pop_back();
            return x;
        }
    }

    void increment(int k, int val)
    {
        int x = k;
        if (arr.size() < k)
        {
            x = arr.size();
        }
        for (int i = 0; i < x; i++)
        {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */