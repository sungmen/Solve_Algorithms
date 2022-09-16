class Solution 
{
public:
    string removeOccurrences(string s, string part) 
    {
        int m = part.size();
        for(;s.size() >= m && s.find(part) < s.size();)
        {
            s.erase(s.find(part), m);
        }
        return s;
    }
};