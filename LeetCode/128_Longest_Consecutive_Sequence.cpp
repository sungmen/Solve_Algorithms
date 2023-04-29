class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int res = 0;
        map<int, int> m, chk;
        for (auto i : nums) m[i] = 1;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (chk.find(it->first) == chk.end())
            {
                chk[it->first] = 1;
                int t = it->first;
                t++;
                int cnt = 1;
                while (m.find(t) != m.end())
                {
                    chk[t++] = 1;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;    
    }
};