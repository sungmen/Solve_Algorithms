class Solution 
{
public:
    static bool comp (vector<int> & a, vector<int> & b)
    {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        if (1 == scores.size()) return scores[0];
        vector<int> dp(scores.size());
        int res = 0;
        vector<vector<int>> v;
        for (int i = 0; i < scores.size(); i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < scores.size(); i++)
        {
            dp[i] = v[i][1];
            for (int j = 0; j < i; j++)
            {
                if (v[i][1] >= v[j][1])
                    dp[i] = max(dp[i], v[i][1] + dp[j]);
                if (res < dp[i])
                    res = dp[i];
            }
        }
        return res;
    }
};