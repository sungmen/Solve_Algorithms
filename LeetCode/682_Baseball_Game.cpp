class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        map<string, int> m;
        m["C"] = 1;
        m["D"] = 2;
        m["+"] = 3;
        for (auto str : ops) {
            switch(m[str]) {
                case 1: {
                    if (!v.empty()) {
                        v.pop_back();
                    }
                    break;
                }
                case 2: {
                    if (!v.empty()) {
                        v.push_back(v.back() * 2);
                    }
                    break;
                }
                case 3: {
                    if (!v.empty()) {
                        v.push_back(v.back() + v[v.size()-2]);
                    }
                    break;
                }
                default: {
                    v.push_back(stoi(str));
                    break;
                }
            }
        }
        int ans = 0;
        for (auto n : v) {
            ans += n;
        }
        return ans;
    }
};