class Solution {
    vector<int> res;
    vector<bool> chk;
    string labels_;
    map<int, vector<int>> v;
public:
    vector<int> dfs(int idx, vector<int> alp)
    {
        vector<int> tmp = alp;
        for (auto it : v[idx])
        {
            if (chk[it]) continue;
            chk[it] = 1;
            vector<int> next = dfs(it, tmp);
            for (int i = 0; i < 26; i++)
            {
                alp[i] += next[i];
            }
        }
        res[idx] += alp[labels_[idx]-'a'];
        alp[labels_[idx]-'a']++;
        return alp;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        labels_ = labels;
        res.resize(n, 1);
        chk.resize(n, 0);
        for (auto edge : edges)
        {
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        chk[0] = 1;
        vector<int> alp(26, 0);
        dfs(0, alp);
        return res;
    }
};

