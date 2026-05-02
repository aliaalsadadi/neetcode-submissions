class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> operands;
        stack<string> operators;
        unordered_set<string> operatorSet = {"+", "-", "*"};
        for (const string &ch : tokens)
        {
            if (ch == "+")
            {
                int first = operands.top();
                operands.pop();
                int second = operands.top();
                operands.pop();
                operands.push(first + second);
            }
            else if (ch == "-")
            {
                int first = operands.top();
                operands.pop();
                int second = operands.top();
                operands.pop();
                operands.push(second - first);
            }
            else if (ch == "*")
            {
                int first = operands.top();
                operands.pop();
                int second = operands.top();
                operands.pop();
                operands.push(first * second);
            }
            else if (ch == "/")
            {
                int first = operands.top();
                operands.pop();
                int second = operands.top();
                operands.pop();
                operands.push(second / first);
            }
            else
            {
                operands.push(stoi(ch));
            }
        }
        return operands.top();
    }

};
