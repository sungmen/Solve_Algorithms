class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> m;
        for (auto wal : wall) {
            int cnt = 0;
            for (auto w : wal) {
                cnt += w;
                if (! m[cnt]) {
                    m[cnt] = 1;
                } else {
                    m[cnt] += 1;
                }
            }
        }
        if (m.size() == 1) return wall.size();
        int minValue = wall.size();
        int sumValue = accumulate(wall[0].begin(), wall[0].end(), 0);
        m.erase(sumValue);
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            if (minValue > (wall.size() - it->second)) minValue = wall.size() - it->second;
        }
        return minValue;
    }
};