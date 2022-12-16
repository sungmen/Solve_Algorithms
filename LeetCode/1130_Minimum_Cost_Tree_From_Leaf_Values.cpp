class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!stk.empty())
            {
                int a = 0;
                if (arr[i] >= stk.top())
                {
                    a = stk.top();
                    stk.pop();
                }
                if (0 == a)
                {
                    break;
                }
                int b = arr[i];
                if (!stk.empty() && arr[i] >= stk.top())
                {
                    b = stk.top();
                }
                res += a * b;
            }
            stk.push(arr[i]);
        }
        if (stk.empty())
            return res;
        int back = stk.top();
        stk.pop();
        while (!stk.empty())
        {
            res += back * stk.top();
            back = stk.top();
            stk.pop();
        }
        return res;
    }
};