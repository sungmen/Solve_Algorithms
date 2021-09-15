class Solution {
public:
    bool checkA(char c) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        int i = 0, r = s.size() - 1;
        while (i < r) {
            if (checkA(s[i]) && checkA(s[r])) {
                char tmp = s[i];
                s[i] = s[r];
                s[r] = tmp;
                i++;
                r--;
            } else if (checkA(s[i])) {
                r--;
            } else if (checkA(s[r])) {
                i++;
            } else {
                r--;
                i++;
            }
        }
        return s;
    }
};