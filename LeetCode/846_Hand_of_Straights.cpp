class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        map<int, int> m;
        for (auto h : hand) {
            m[h] ++;
        }
        while (!m.empty()) {
            int it = m.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (m.find(it + i) == m.end()) return false;
                m[it + i]--;
                if (0 == m[it+i]) {
                    m.erase(it + i);
                }
            }
        }
        return true;
    }
};