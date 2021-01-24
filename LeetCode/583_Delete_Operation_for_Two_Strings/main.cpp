/**
* Runtime: 8 ms, faster than 95.18% of C++ online submissions for Delete Operation for Two Strings.
* Memory Usage: 7.5 MB, less than 88.71% of C++ online submissions for Delete Operation for Two Strings.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int d[word1.size()+1][word2.size()+1];
        memset(d, 0, sizeof(d));
        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word2.size(); j++) {
                if (word1[i] == word2[j]) d[i+1][j+1] = d[i][j] + 1;
                else d[i+1][j+1] = max(d[i+1][j], d[i][j+1]);
            }
        }
        return word1.size() + word2.size() - d[word1.size()][word2.size()] * 2;
    }
};