bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        long long answer = 0, back = LONG_MIN;
        sort(points.begin(), points.end(), comp);
        for (auto point : points) {
            if (back < point[0]) {
                back = point[1];
                ++ answer;
            }
        }
        return answer;
    }
};