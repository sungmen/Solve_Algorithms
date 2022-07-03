/**
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Isomorphic Strings.
* Memory Usage: 7.4 MB, less than 56.51% of C++ online submissions for Isomorphic Strings.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v(127, -1);
        vector<int> v2(127, -1);
        for (int i = 0; i < s.size(); i++) {
            if (v[s[i]] == -1) v[s[i]] = t[i];
            else if (v[s[i]] != t[i]) {
                return false;
            }
            if (v2[t[i]] == -1) v2[t[i]] = s[i];
            else if (v2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};