class Solution 
{
public:
    string finalString(string s) 
    {
        string r = "";
        for (auto c : s)
        {
            if ('i' == c)
            {
                reverse(r.begin(), r.end());
                continue;
            }
            
            r += c;
        }
        return r;
    }
};