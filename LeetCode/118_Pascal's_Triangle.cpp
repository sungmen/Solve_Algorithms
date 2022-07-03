class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for (int i = 0; i < numRows; i++) {
            vector<int> m(i+1, 1);
            for (int j = 1; j < i ; j++) {
                m[j] = v[i-1][j] + v[i-1][j-1];
            }
            v.push_back(m);
        }
        return v;
    }
};