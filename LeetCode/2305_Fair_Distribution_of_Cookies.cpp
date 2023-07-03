class Solution 
{
public:
    int ans = 1e9;

    void dfs(vector<int>& cookies, int cur, vector<int> v)
    {
        if (cookies.size() == cur)
        {
            int res = 0;
            for (int i = 0; i < v.size(); i++)
            {
                res = max(res, v[i]);
            }
            ans = min(ans, res);
            return;
        }
        for (int i = 0; i < v.size(); i++)
        {
            v[i] += cookies[cur];
            if (v[i] > ans)
            {
                v[i] -= cookies[cur];
                continue;
            }
            dfs(cookies, cur + 1, v);
            v[i] -= cookies[cur];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) 
    {
        if (cookies.size() == k)
        {
            int tmp = 0;
            for (int i = 0; i < k; i++)
            {
                tmp = max(cookies[i], tmp);
            }
            return tmp;
        }
        vector<int> v(k, 0);
        for (int i = 0; i < k; i++)
            dfs(cookies, 0, v);
        return ans;
    }
};