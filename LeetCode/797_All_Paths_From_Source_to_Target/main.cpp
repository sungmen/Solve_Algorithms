class Solution {
private:
    vector<vector<int>> graph;
    vector<vector<int>> res;
    int end;
    
public:
    void dfs(int idx, vector<int> v) {
        v.push_back(idx);
        
        if (idx == end - 1) {
            res.push_back(v);
            return;
        }
        
        for (auto g : graph[idx]) {
            dfs(g, v);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;
        end = graph.size();
        int idx = 0;
        
        for (auto g : graph[idx]) {
            dfs(g, {0});
        }
        
        return res;
    }
};