class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string revstr = str;
        reverse(revstr.begin(), revstr.end());
        return !str.compare(revstr);
    }
};