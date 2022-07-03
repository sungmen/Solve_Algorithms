/**
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Case Permutation.
* Memory Usage: 9.4 MB, less than 93.51% of C++ online submissions for Letter Case Permutation.
*/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> str;
        queue<int> q;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                q.push(i);
            } else if (S[i] >= 'A' && S[i] <= 'Z') {
                S[i] -= ('A'-'a');
                q.push(i);
            }
        }
        str.push_back(S);
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            int SIZE = str.size();
            for (int f = 0; f < SIZE; f++) {
                string s_tmp = str[f];
                str[f][i] += ('A'-'a');
                str.push_back(s_tmp);
            }
        }
        return str;
    }
};