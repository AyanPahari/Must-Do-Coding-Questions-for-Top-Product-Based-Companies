class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> s;
    int min = INT_MAX;

    MinStack()
    {
        //nothing here
    }

    void push(int val)
    {
        if (s.size() == 0)
        {
            s.push(val);
            min = val;
        }
        if (val >= min)
        {
            s.push(val);
        }
        if (val < min)
        {
            int x = 2 * val - min; //insert flag using 2X-ME
            s.push(x);
            min = val;
        }
    }

    void pop()
    {
        if (s.top() < min)
        {
            min = 2 * min - s.top(); //retrieve the prev minimum using 2ME-Y
            s.pop();
        }
        else
        {
            s.pop();
        }
    }

    int top()
    {
        if (s.top() < min)
        {
            return min;
        }
        else
        {
            return s.top();
        }
    }

    int getMin()
    {
        if (s.size() == 0)
        {
            return -1;
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */