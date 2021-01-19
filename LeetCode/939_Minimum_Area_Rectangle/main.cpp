/**
* Runtime: 768 ms, faster than 68.60% of C++ online submissions for Minimum Area Rectangle.
* Memory Usage: 22.8 MB, less than 38.72% of C++ online submissions for Minimum Area Rectangle.
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int>> m;
        for (auto p : points) {
            m[p[0]].insert(p[1]);
        }
        int MIN = INT_MAX;
        for (int i = 0; i < points.size()-1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    bool chk = true;
                    if (m.find(points[i][0]) != m.end() && m.find(points[j][0]) != m.end()) {
                        set<int>::iterator iter, iter2;
                        iter = m.find(points[i][0])->second.find(points[j][1]);
                        iter2 = m.find(points[j][0])->second.find(points[i][1]);
                        if (iter != m.find(points[i][0])->second.end() && iter2 != m.find(points[j][0])->second.end()) {
                            int x = abs(points[i][0] - points[j][0]);
                            int y = abs(points[i][1] - points[j][1]);
                            MIN = MIN > x * y ? x*y : MIN;
                        }
                    }
                }
            }
        }
        return MIN == INT_MAX ? 0 : MIN;
    }
};