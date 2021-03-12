class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;
        int val = 1<<k;
        map<string, int> m;
        int cnt = 0;
        for (int i = 0; i < s.size()-k+1; i++) {
            m[s.substr(i, k)] = 1;
            if (m.size() == val) return true;
        }
        return false;
    }
};