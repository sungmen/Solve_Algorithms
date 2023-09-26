class Solution 
{
public:
    int appendCharacters(string s, string t) 
    {
        int tIdx = 0;
        for (int i = 0; i < s.size() && tIdx < t.size(); i++)
        {
            if (s[i] == t[tIdx])
            {
                tIdx++;
            }
        }
        return t.size() - tIdx;
    }
};