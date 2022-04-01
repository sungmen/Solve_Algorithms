class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            int l = i, r = i + k - 1;
            if (r >= s.size()) r = s.size() - 1;
            while (l < r) {
                swap(s[l], s[r]);
                l++, r--;
            }
        }
        return s;
    }
};