class Solution {
public:
    int removePalindromeSub(string s) {
        if (!s.size()) return 0;
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size()-1-i]) return 2;
        }
        return 1;
    }
};