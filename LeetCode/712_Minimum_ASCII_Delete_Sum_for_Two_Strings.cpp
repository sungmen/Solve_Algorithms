class Solution 
{
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        int sum = 0;
        for (auto c : s1) sum += c;
        for (auto c : s2) sum += c;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 1; i <= s1.size(); i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                dp[i][j] = (s1[i-1] == s2[j-1]) ? int(s1[i-1]) + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return sum - (2 * dp[s1.size()][s2.size()]);
    }
};