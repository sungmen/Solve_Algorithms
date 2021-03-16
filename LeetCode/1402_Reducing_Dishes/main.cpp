/**
* Runtime: 4 ms, faster than 84.90% of C++ online submissions for Reducing Dishes.
* Memory Usage: 8 MB, less than 71.62% of C++ online submissions for Reducing Dishes.
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        if (satisfaction.back() <= 0) return 0;
        int tmp_sum = satisfaction.back();
        int res = satisfaction.back();
        int ans = satisfaction.back();
        for (int i = satisfaction.size()-2; i >= 0; i--) {
            res += (tmp_sum + satisfaction[i]);
            tmp_sum += satisfaction[i];
            if (ans < res) ans = res;
        }
        return ans;
    }
};