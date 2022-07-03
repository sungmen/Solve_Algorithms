class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int ans = 0;
        for (auto log : logs) 
        {
            if (log == "../") 
            {
                ans = max(0, ans - 1);
            }
            else if (log != "./")
            {
                ans++;
            }
        }
        return ans;
    }
};