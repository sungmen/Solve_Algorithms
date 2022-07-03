class Solution {
private:
    int start[100001];
    int end[100001];
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        for (auto i : edges) {
            start[i[0]]++;
            end[i[1]]++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (start[i] && !end[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};