/**
* Runtime: 8 ms, faster than 81.99% of C++ online submissions for Valid Anagram.
* Memory Usage: 7.3 MB, less than 99.51% of C++ online submissions for Valid Anagram.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int arr['z' - 'a' + 1];
        int arr2['z' - 'a' + 1];
        memset(arr, 0, sizeof(arr));
        memset(arr2, 0, sizeof(arr2));
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a'] ++;
            arr2[t[i] - 'a'] ++;
        }
        for (int i = 0; i < 'z'-'a'+1; i++) {
            if (arr[i]) {
                if(arr[i] != arr2[i]) return false;
            }
        }
        return true;
    }
};