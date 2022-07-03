class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        map<int, int> m;
        for (auto i : nums) {
            if (m.find(i) == m.end()) {
                m[i] = 1;
            } else {
                m.find(i)->second++;
            }
        }
        for (map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};