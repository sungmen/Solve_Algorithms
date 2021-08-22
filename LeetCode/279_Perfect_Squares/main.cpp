class Solution {
public:
    int numSquares(int n) {
        map<int, int> m;
        for (int i = 1; i <= 100; ++i) {
            m[i*i] = 1;
        }
        queue<pair<int, int>> q;
        q.push({n, 0});
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (m[cur.first]) {
                return cur.second + 1;
            }
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (it->first > cur.first) break;
                q.push({cur.first - it->first, cur.second + 1});
            }
        }
        return -1;
    }
};