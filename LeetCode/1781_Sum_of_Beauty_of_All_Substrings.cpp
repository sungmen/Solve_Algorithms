class Solution 
{
public:
    int beautySum(string s) 
    {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            map<char, int> m;
            for (int j = i; j < n; j++)
            {
                m[s[j]]++;
                using p = decltype(m)::value_type;
                auto it = max_element(begin(m), end(m), [](const p & p1, const p & p2) {return p1.second < p2.second;});
                auto it2 = min_element(begin(m), end(m), [](const p & p1, const p & p2) {return p1.second < p2.second;});
                res += it->second - it2->second;
            }
        }

        return res;    
    }
};