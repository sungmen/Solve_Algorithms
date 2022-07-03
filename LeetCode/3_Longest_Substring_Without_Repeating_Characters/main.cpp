/*
    Runtime: 4 ms, faster than 97.86% of C++ online submissions for Longest Substring Without Repeating Characters.
    Memory Usage: 7.2 MB, less than 97.36% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int chk[127];
        memset(chk, -1, sizeof(chk));
        int l = 0, r = 0;
        int max_value = 1;
        for (r = 0; r < s.size(); r++) {
            if (chk[s[r]] >= l && chk[s[r]] < r) {
                l = chk[s[r]] + 1;
                chk[s[r]] = r;
            } else {
                chk[s[r]] = r;
            }
            if(max_value < r - l + 1) max_value = r - l + 1;
        }
        return max_value;
    }
};