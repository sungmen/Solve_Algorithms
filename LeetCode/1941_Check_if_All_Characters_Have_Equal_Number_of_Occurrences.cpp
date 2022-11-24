class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for (auto c : s) {
            arr[c-'a']++;
        }
        int t = 0;
        for (int i = 0; i < 26; i++) {
            if (0 == t && arr[i]) {
                t = arr[i];
            }
            if (0 != t && 0 != arr[i] && t != arr[i]) {
                return false;
            }
        }
        return true;
    }
};