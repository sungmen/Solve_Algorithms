class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) {
                if (end < intervals[i][1]) end = intervals[i][1];
            } else {
                vector<int> in_v = {start, end};
                res.emplace_back(in_v);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> in_v = {start, end};
        res.emplace_back(in_v);
        return res;
    }
};