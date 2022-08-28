class Solution 
{
public:
    int cnt = 0;
    int arr[(int)1e5+1];
    map<int, vector<int>> m;
    
    void dfs(int n)
    {
        for (auto i : m[n])
        {
            if (! arr[i])
            {
                cnt ++;
                arr[i] = 1;
                dfs(i);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        for (auto edge : edges)
        {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        
        for (auto res : restricted)
        {
            arr[res] = 1;
        }
        
        arr[0] = 1;
        dfs(0);
        
        return cnt + 1;
    }
};