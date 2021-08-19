class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        vector<int> xp, yp, res;
        if (x != 1) for (int i = 1; i < bound; i *= x) xp.push_back(i);
        else xp.push_back(1);
        if (y != 1) for (int i = 1; i < bound; i *= y) yp.push_back(i);
        else yp.push_back(1);
        for (int i = 0; i < xp.size(); ++i) {
            for (int j = 0; j < yp.size(); ++j) {
                if (xp[i] + yp[j] > bound) break;
                s.insert(xp[i] + yp[j]);
            }
        }
        for (auto it = s.begin(); it != s.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }
};