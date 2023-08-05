class Solution
{
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_map<string, int> um;
        int n = s.size();
        for (auto d : dictionary)
            um[d]++;
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i-1] + 1;
            for (int j = i; j >= 1; j--)
            {
                if (um.find(s.substr(j-1,i-j+1)) == um.end()) continue;
                dp[i] = min(dp[j-1], dp[i]);
            }
        }

        return dp[n];
    }
};