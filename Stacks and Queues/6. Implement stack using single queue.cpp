class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        //using single queue
        q.push(x);
        int size = q.size();
        size--;
        while (size--)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (q.empty())
            return -1;
        else
        {
            int k = q.front();
            q.pop();
            return k;
        }
    }

    /** Get the top element. */
    int top()
    {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        if (q.empty())
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