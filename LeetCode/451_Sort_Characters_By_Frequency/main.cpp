class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (auto c : s) {
            if (m.find(c) == m.end()) {
                m[c] = 1;
            } else {
                m[c]++;
            }
        }
        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char,int> b){return a.second > b.second;});
        string answer = "";
        for (auto vv : v) {
            string tmp(vv.second, vv.first);
            answer += tmp;
        }
        return answer;
    }
};