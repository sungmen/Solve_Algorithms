class Solution 
{
private:
    int res = -1;
    int cnt = 1;
    int chk[100001];
    int coun[100001];
public:
    void dfs(int n, vector<int>& edges, int c)
    {
        chk[n] = cnt;
        int _next = edges[n];
        if (_next == -1) return;
        if (chk[_next] == 0)
        {
            coun[_next] = c + 1;
            dfs(_next, edges, c+1);
        }
        else if (chk[_next] == chk[n])
        {
            res = max(res, c - coun[_next] + 1);
        }
    }

    int longestCycle(vector<int>& edges) 
    {
        memset(chk, 0, sizeof(chk));
        memset(coun, 0, sizeof(coun));
        for (int idx = 0; idx < edges.size(); idx++)
        {
            if (chk[idx] != 0) continue;
            coun[idx] = 1;
            dfs(idx, edges, 1);
            cnt++;
        }
        return res; 
    }
};