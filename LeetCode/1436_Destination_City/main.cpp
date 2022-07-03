class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> m;
        for (auto p : paths) {
            if(m.find(p[0]) == m.end()) {
                m[p[0]] = p[1];
            }
        }
        string str = paths[0][0];
        while(m.find(str) != m.end()) {
            str = m.find(str)->second;
        }
        return str;
    }
};