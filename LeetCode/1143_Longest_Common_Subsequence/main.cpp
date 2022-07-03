/**
* Runtime: 12 ms, faster than 83.53% of C++ online submissions for Longest Common Subsequence.
* Memory Usage: 10.5 MB, less than 87.42% of C++ online submissions for Longest Common Subsequence.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int d[text1.size()+1][text2.size()+1];
        memset(d, 0, sizeof(d));
        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    d[i+1][j+1] = d[i][j] + 1;
                } else {
                    d[i+1][j+1] = max(d[i][j+1], d[i+1][j]);
                }
            }
        }
        return d[text1.size()][text2.size()];
    }
};