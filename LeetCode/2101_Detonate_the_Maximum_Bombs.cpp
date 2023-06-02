class Solution 
{
public:

    int dfs(vector<long long> v[], vector<bool> &chk, int idx)
    {
        chk[idx] = 1;
        int res = 1;
        for (auto i : v[idx])
        {
            if (chk[i]) continue;
            res += dfs(v, chk, i);
        }
        return res;
    }

    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int res = 0;
        int n = bombs.size();
        vector<long long> v[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                long long a = bombs[i][0] - bombs[j][0];
                long long b = bombs[i][1] - bombs[j][1];
                double t = sqrt(a * a + b * b);
                if (bombs[i][2] >= t)
                {
                    v[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            vector<bool> chk(n);
            res = max(res, dfs(v, chk, i));
        }
        return res;    
    }
};