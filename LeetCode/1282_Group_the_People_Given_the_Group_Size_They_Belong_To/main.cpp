class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>> res;
        map <int, vector<int>> m;
        for (int i = 0; i < gs.size(); i++) {
            if (m.find(gs[i]) == m.end()) {
                m[gs[i]].push_back(i);
            } else {
                m[gs[i]].push_back(i);
            }
            if (m[gs[i]].size() == gs[i]) {
                res.push_back(m.find(gs[i])->second);
                m.erase(gs[i]);
            }
        }
        for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};