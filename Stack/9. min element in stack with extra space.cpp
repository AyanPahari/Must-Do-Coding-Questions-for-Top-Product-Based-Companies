class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> ss;

    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        if (ss.size() == 0 || val <= ss.top())
        {
            ss.push(val);
        }
    }

    void pop()
    {
        if (s.top() > ss.top())
        {
            s.pop();
        }
        else
        {
            s.pop();
            ss.pop();
        }
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return ss.top();
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