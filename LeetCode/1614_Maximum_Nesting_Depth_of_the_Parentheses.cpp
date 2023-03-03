class Solution 
{
public:
    int maxDepth(string s) 
    {
        int cnt = 0;
        int ans = 0;
        for (auto c : s)
        {
            if (c == '(') cnt++;
            if (c == ')') cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};