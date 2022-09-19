class Solution 
{
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int t = target.size();
        unordered_map<int, int> um, back_um;
        for (auto num : nums)
        {
            bool chk = 1;
            int nsize = num.size();
            if (nsize > t) continue;
            for (int i = 0; i < nsize; i++)
            {
                if (target[i] != num[i])
                {
                    chk = 0;
                    break;
                }
            }
            if (chk)
            {
                um[nsize]++;
            }
            chk = 1;
            for (int i = 0; i < nsize; i++)
            {
                if (target[t-1-i] != num[nsize-1-i])
                {
                    chk = 0;
                    break;
                }
            }
            if (chk)
            {
                back_um[nsize]++;
            }
        }
        
        int res = 0;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            int backNum = back_um[t-(it->first)];
            if (backNum)
            {
                if (!(target.size() % 2) && target.substr(0, t/2) == target.substr(t/2) && it->first == t/2)
                {
                    if (it->second != 1)
                    {
                        res += (it->second * (it->second - 1));
                    }
                }
                else
                {
                    res += it->second * backNum;
                }
            }
        }
        
        return res;
    }
};