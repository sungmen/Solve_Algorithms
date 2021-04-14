class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> m;
        vector<vector<string>> res;
        int idx = 1;
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (!m[tmp]) {
                m[tmp] = idx++;
                vector<string> v;
                v.push_back(str);
                res.push_back(v);
            } else {
                int id = m.find(tmp)->second;
                res[id-1].push_back(str);
            }   
        }
        return res;
    }
};