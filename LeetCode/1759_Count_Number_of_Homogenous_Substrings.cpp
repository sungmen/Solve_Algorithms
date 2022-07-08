class Solution 
{
public:    
    int countHomogenous(string s) 
    {
        
        constexpr long long MOD = 1e9 + 7;
        char back = s[0];
        long long res = 1;
        unordered_map<char, long long> m;
        
        for (int i = 1; i < s.size(); i++)
        {
            if (back == s[i])
            {
                res++;
            }
            else
            {
                m[back] += (res * (res + 1) / 2);
                res = 1;
            }
            back = s[i];
        }
        m[s.back()] += (res * (res + 1) / 2);
        
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            ans += (it->second % MOD);
        }
        
        return ans;
    }
};