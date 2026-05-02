class MinStack
{
public:
    stack<int> st;
    stack<int> minSt;
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        val = minSt.empty() ? val : min(minSt.top(), val);
        minSt.push(val);
    }

    void pop()
    {
        st.pop();
        minSt.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};
