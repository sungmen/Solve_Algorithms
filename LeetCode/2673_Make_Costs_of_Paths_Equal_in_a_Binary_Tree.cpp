class Solution 
{
public:
    int ans = 0;

    int dfs(int n, vector<int>& cost, int idx)
    {
        if (n < idx) return 0;
        int l = dfs(n, cost, idx * 2);
        int r = dfs(n, cost, (idx * 2) + 1);

        if (l != r)
            ans += abs(l - r);
        return cost[idx - 1] + max(l, r);
    }

    int minIncrements(int n, vector<int>& cost)
    {
        dfs(n, cost, 1);
        return ans;
    }
};