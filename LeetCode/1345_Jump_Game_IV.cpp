class Solution 
{
public:
    int minJumps(vector<int>& arr) 
    {
        if (1 == arr.size()) return 0;
        int ans = 0;
        map<int, vector<int>> m;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            m[arr[i]].push_back(i);
        }
        vector<bool> chk(n, 0);
        queue<int> q;
        chk[0] = 1;
        q.push(0);
        while (!q.empty())
        {
            int si = q.size();
            while (si--)
            {
                int cur = q.front();
                q.pop();
                if (cur == n - 1)
                    return ans;
                vector<int> v = m[arr[cur]];
                if (cur - 1 > 0 && ! chk[cur - 1])
                {
                    chk[cur - 1] = 1;
                    q.push(cur - 1);
                }
                if (cur + 1 < n && ! chk[cur + 1])
                {
                    chk[cur + 1] = 1;
                    q.push(cur + 1);
                }
                for (auto i : v)
                {
                    if (chk[i]) continue;
                    chk[i] = 1;
                    q.push(i);
                }
                m[arr[cur]].clear();
            }
            ans++;
        }
        return ans;
    }
};
