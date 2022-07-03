class Solution {
public:
    map<char, pair<int, int>> m;
    bool judgeCircle(string moves) {
        m['L'] = {0, -1};
        m['R'] = {0, 1};
        m['U'] = {-1, 0};
        m['D'] = {1, 0};
        pair<int, int> cur = {0, 0};
        for (auto str : moves) {
            cur.first += m[str].first;
            cur.second += m[str].second;
        }
        if (cur.first == 0 && cur.second == 0) {
            return true;
        } else {
            return false;
        }
    }
};