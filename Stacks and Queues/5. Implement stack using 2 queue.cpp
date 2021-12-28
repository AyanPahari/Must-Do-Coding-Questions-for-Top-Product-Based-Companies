class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        //using 2 queue's
        q2.push(x);
        while (!q1.empty())
        {
            int k = q1.front();
            q2.push(k);
            q1.pop();
        }
        while (!q2.empty())
        {
            int k = q2.front();
            q1.push(k);
            q2.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (q1.empty())
            return -1;
        else
        {
            int k = q1.front();
            q1.pop();
            return k;
        }
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        if (q1.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */