class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> com;
        for (int i = 1; i <= n; ++i) com.push_back(i);
        vector<bool> tmp(com.size(), false);
        for (int i = 0; i < k; ++i) tmp[i] = true;
        vector<vector<int>> res;
        do {
            vector<int> r;
            for (int i = 0; i < com.size(); ++i) {
                if (tmp[i]) {
                    r.push_back(com[i]);
                }
            }
            res.push_back(r);
        } while(prev_permutation(tmp.begin(), tmp.end()));
        return res;
    }
};