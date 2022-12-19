class Solution 
{
private:
    map<int, vector<int>> m;
    map<int, bool> chk;
    bool res = false;
    int dest;
public:
    void dfs(int cur)
    {
        if (cur == dest)
            res = true;
        if (res)
            return;
        for (auto next : m[cur])
        {
            if (chk.find(next) == chk.end())
            {
                chk[next] = 1;
                dfs(next);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        dest = destination;
        for (auto edge : edges)
        {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        chk[source] = 1;
        dfs(source);
        return res;
    }
};