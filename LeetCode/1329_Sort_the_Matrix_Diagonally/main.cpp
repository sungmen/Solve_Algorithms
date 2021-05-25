class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, vector<int>> m;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                m[j - i].push_back(mat[i][j]);
            }
        }
        for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
            sort(it->second.begin(), it->second.end());
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mat[i][j] = m[j - i].front();
                m[j-i].erase(m[j-i].begin());
            }
        }
        return mat;
    }
};