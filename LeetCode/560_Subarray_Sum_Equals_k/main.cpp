/**
* Runtime: 348 ms, faster than 5.26% of C++ online submissions for Subarray Sum Equals K.
* Memory Usage: 50.9 MB, less than 7.11% of C++ online submissions for Subarray Sum Equals K.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int dp[nums.size()];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) dp[i] = dp[i-1] + nums[i];
        map<int, vector<int>> m;
        m[0].push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            m[dp[i]].push_back(i);
        }
        int cnt = 0;
        for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); ++it) {
            int sum = k + it->first;
            if(m.find(sum) != m.end()) {
                for (auto start : it->second) {
                    for (auto end : m.find(sum)->second) {
                        if (start < end) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
