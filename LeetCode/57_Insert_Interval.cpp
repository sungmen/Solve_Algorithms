class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int l = 0, r = 0;
        while(l < intervals.size() && intervals[l][0] < newInterval[0])
        {
            l++;
        }
        bool lchk = 0;
        if (l > 0 && intervals[l-1][1] >= newInterval[0])
        {
            lchk = 1;
            l--;
        }
        for (int i = 0; i < l;i++)
            result.push_back(intervals[i]);
        vector<int> tmp;
        tmp.push_back((lchk?intervals[l][0]:newInterval[0]));
        r = l;
        while(r < intervals.size() && intervals[r][0] <= newInterval[1])
        {
            r++;
        }
        bool rchk = 0;
        if (r > 0 && intervals[r-1][1] >= newInterval[1])
        {
            rchk = 1;
            r--;
        }
        tmp.push_back((rchk?intervals[r][1]:newInterval[1]));
        result.push_back(tmp);
        for (int i = (rchk?r+1:r); i < intervals.size(); i++)
            result.push_back(intervals[i]);
        return result;
    }
};