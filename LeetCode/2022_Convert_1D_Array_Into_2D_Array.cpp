class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            res.push_back(vector<int>(original.begin()+(n*i), original.begin()+(i * n + n)));
        }
        return res;
    }
};