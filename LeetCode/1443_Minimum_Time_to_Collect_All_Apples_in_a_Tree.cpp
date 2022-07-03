class Solution {
public:
    int res = 0;
    vector<bool> check, chk, has;
    vector<vector<int>> edge;
    
    void dfs(vector<int> v, int idx) {
        if (has[idx]) {
            for (int i = v.size() - 1; i >= 0; i--) {
                if (!check[v[i]]) {
                    check[v[i]] = 1;
                    res++;
                } else break;
            }
        }
        for (auto i : edge[idx]) {
            if (!chk[i]) {
                chk[i] = 1;
                vector<int> tmp = v;
                tmp.push_back(i);
                dfs(tmp, i);
            }
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        check.resize(n, 0);
        chk.resize(n, 0);
        edge.resize(n);
        has = hasApple;
        for (auto i : edges) {
            edge[i[0]].push_back(i[1]);
            edge[i[1]].push_back(i[0]);
        }
        vector<int> v;
        v.push_back(0);
        chk[0] = 1;
        dfs (v, 0);
        return (res?(res-1)*2:0);
    }
};