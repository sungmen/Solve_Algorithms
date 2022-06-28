class Solution {
public:
    int longestPalindrome(string s) {
        map<int, int> m;
        for (auto c : s)
        {
            m[c]++;
        }
        int ans = 0;
        int chk = 0;
        for (auto it = m.begin() ; it != m.end(); it++)
        {
            if (it->second % 2)
            {
                ans += it->second - 1;
                if (chk < it->second)
                {
                    chk = it->second;
                }
            }
            else
            {
                ans += it->second;
            }
        }
        return (chk != 0) + ans;
    }
};