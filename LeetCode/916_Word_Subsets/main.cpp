/**
* Runtime: 416 ms, faster than 26.37% of C++ online submissions for Word Subsets.
* Memory Usage: 133.9 MB, less than 25.72% of C++ online submissions for Word Subsets.
*/

class Solution {
public:
    int var[10001][26];
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        map<char, int> m[A.size()];
        vector<string> ans;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (m[i].find(A[i][j]) != m[i].end()) {
                    m[i][A[i][j]] += 1;
                } else {
                    m[i][A[i][j]] = 1;
                }
            }
        }
        map<char, int> mc;
        for (int i = 0; i < B.size(); i++) {
            for (int j = 0; j < B[i].size(); j++) {
                var[i][(B[i][j]-'a')]++;
                if (mc.find(B[i][j]) == mc.end()) {
                    mc[B[i][j]] = 1;
                } else {
                    if (mc.find(B[i][j])->second < var[i][(B[i][j]-'a')]) {
                        mc[B[i][j]] = var[i][(B[i][j]-'a')];
                    }
                }
            }
        }
        for (int i = 0; i < A.size(); i++) {
            bool chk = true;
            for (map<char, int>::iterator it = mc.begin(); it != mc.end(); it++) {
                if (m[i].find(it->first) == m[i].end()) {
                    chk = false;
                    break;
                } else {
                    if (m[i].find(it->first)->second < it->second) {
                        chk = false;
                        break;
                    }
                }
            }
            if (chk) {
                ans.push_back(A[i]);
            }
        }
        return ans;
    }
};