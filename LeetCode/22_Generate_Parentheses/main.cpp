/**
*   Runtime: 12 ms, faster than 17.05% of C++ online submissions for Generate Parentheses.
*   Memory Usage: 13.8 MB, less than 55.58% of C++ online submissions for Generate Parentheses.
*/
class Solution {
public:
    vector<string> res;
    int n_;
    void backt(string str, int l, int r) {
        if(l < n_) {
            if(r < l) {
                backt(str+')', l, r + 1);
            }
            backt(str+'(', l + 1, r);
        } else if (l == n_ && r < l) {
            backt(str+')', l, r + 1);
        }
        if (l==n_ && r == n_) {
            res.push_back(str);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        n_ = n;
        backt("(", 1, 0);
        return res;
    }
};