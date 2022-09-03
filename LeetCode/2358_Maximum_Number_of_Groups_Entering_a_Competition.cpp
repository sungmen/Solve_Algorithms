class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int res = 0, i = 0;
        for (i = 1; i <= 100000 && res+i <= grades.size(); i ++)
        {
            res += i;
        }
        return --i;
    }
};