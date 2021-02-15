class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, vector<int>> m;
        for (int r = 0; r < mat.size(); r++) {
            int cnt = 0;
            for (int w = 0; w < mat[0].size(); w++) {
                cnt += mat[r][w];
            }
            m[cnt].push_back(r);
        }
        vector<int> result;
        int cnt = 0;
        for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
            for (auto i : it->second) {
                result.push_back(i);
                cnt++;
                if (cnt == k) break;
            }
            if (cnt == k) break;
        }
        return result;
    }
};