class Solution 
{
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> same, dif, chk;
        for (auto m : words)
        {
            if (m[0] == m[1])
            {
                same[m] ++;
            }
            else
            {
                dif[m] ++;
            }
        }
        int res = 0;
        int odd = 0;
        for (auto it = same.begin(); it != same.end(); it++)
        {
            if (it->second % 2) {
                odd = 2;
                res += (it->second - 1) * 2;
            }
            else
            {
                res += (it->second) * 2;
            }
        }
        res += odd;
        for (auto it = dif.begin(); it != dif.end(); it++)
        {
            string cur = it->first;
            string tmp = "";
            tmp += cur[1];
            tmp += cur[0];
            if (dif.find(tmp) != dif.end() && chk.find(tmp) == chk.end())
            {
                chk[it->first] = 1;
                chk[tmp] = 1;
                res += (min(dif[tmp], it->second)*4);
            }
        }
        return res;
    }
};