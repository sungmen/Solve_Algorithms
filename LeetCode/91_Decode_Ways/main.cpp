/**
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
* Memory Usage: 6.5 MB, less than 64.79% of C++ online submissions for Decode Ways.
*/
class Solution {
public:
    int numDecodings(string s) {
        int dp[s.size()];
        memset(dp, 0, sizeof(dp));
        int cnt = s[s.size() - 1] - '0';
        if (cnt > 0) dp[s.size() - 1] = 1;
        if (s.size() == 1) return dp[0];
        cnt = s[s.size() - 2] - '0';
        if (cnt > 0) {
            dp[s.size() - 2] = dp[s.size() - 1];
            cnt *= 10;
            cnt += (s[s.size() - 1] - '0');
            if (cnt > 0 && cnt < 27) dp[s.size() - 2] += 1;
        }
        if (s.size() == 2) return dp[0];
        for (int i = s.size() - 3; i >= 0; i--) {
            cnt = s[i] - '0';
            if (cnt > 0) dp[i] += dp[i + 1];
            else continue;
            cnt *= 10;
            cnt += s[i + 1] - '0';
            if (cnt > 0 && cnt < 27) dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};