class Solution {
public:
    vector<vector<int>> answer;
    void dfs(vector<int> v, int cnt, int idx, int num) {
        if (cnt == 0) {
            if (idx == 0) answer.push_back(v);
            return;
        }
        for (int i = min(9, num - 1); i >= cnt; --i) {
            if (idx - i < 0) continue;
            vector<int> tmp = v;
            tmp.push_back(i);
            dfs(tmp, cnt - 1, idx - i, i);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        dfs(v, k, n, n);
        return answer;
    }
};