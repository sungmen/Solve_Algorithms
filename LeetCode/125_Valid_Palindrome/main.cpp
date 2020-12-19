/*
    Runtime: 12 ms, faster than 12.66% of C++ online submissions for Valid Palindrome.
    Memory Usage: 7.7 MB, less than 40.94% of C++ online submissions for Valid Palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            int str_l = -1;
            int str
            _r = -1;
            while((s[l] < 'a' || s[l] > 'z') && (s[l] < 'A' || s[l] > 'Z') && (s[l] < '0' || s[l] >'9') && l < r) l++;
            while((s[r] < 'a' || s[r] > 'z') && (s[r] < 'A' || s[r] > 'Z') && (s[r] < '0' || s[r] >'9') && l < r) r--;
            if(s[l]>='a' && s[l] <= 'z') str_l = s[l] - 'a';
            else if(s[l]>='A' && s[l] <= 'Z') str_l = s[l] - 'A';
            else if(s[l]>='0' && s[l] <= '9') str_l = s[l] - '0' + 27;
            if(s[r]>='a' && s[r] <= 'z') str_r = s[r] - 'a';
            else if(s[r]>='A' && s[r] <= 'Z') str_r = s[r] - 'A';
            else if(s[r]>='0' && s[r] <= '9') str_r = s[r] - '0' + 27;
            if(str_l != str_r) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};