class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> vv(s1.size()+1, vector<bool>(s2.size()+1, 0));
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (!i && !j) {
                    vv[i][j] = 1;
                } else if (!i) {
                    vv[i][j] = (vv[i][j-1] && s2[j-1] == s3[i+j-1]);
                } else if (!j) {
                    vv[i][j] = (vv[i-1][j] && s1[i-1] == s3[i+j-1]);
                } else {
                    vv[i][j] = ((vv[i][j-1] && s2[j-1] == s3[i+j-1]) || (vv[i-1][j] && s1[i-1] == s3[i+j-1]));
                }
            }
        }
        return vv[s1.size()][s2.size()];
    }
};