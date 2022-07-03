/**
* Runtime: 12 ms, faster than 42.51% of C++ online submissions for Min Cost Climbing Stairs.
* Memory Usage: 13.9 MB, less than 30.83% of C++ online submissions for Min Cost Climbing Stairs.
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size()+1, 0);
        if (n == 0 || n == 1 || n == 2) return 0;
        else {
            for (int i = 2; i <= n; i++) {
                dp[i] = min(cost[i-2]+dp[i-2],cost[i-1]+dp[i-1]);
            }
        }
        return dp[n];
    }
};