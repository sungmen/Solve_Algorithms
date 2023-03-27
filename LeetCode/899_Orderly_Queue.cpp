class Solution 
{
public:
    string orderlyQueue(string s, int k) 
    {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        for (int idx = 1; idx < s.size(); idx++)
        {
            res = min(res, s.substr(idx, s.size() - 1) + s.substr(0, idx));
        }
        return res;
    }
};