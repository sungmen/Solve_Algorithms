class Solution {
public:
    int maxPower(string s) {
        int ans = 1, res = 1;
        char b = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (b != s[i])
            {
                ans = 1;
            }
            else
            {
                ans ++;
            }
            b = s[i];
            
            res = max(res, ans);
        }
        return res;
    }
};