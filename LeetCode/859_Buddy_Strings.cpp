class Solution 
{
public:
    int chk[26];
    bool buddyStrings(string s, string goal) 
    {
        if (s.size() != goal.size() || s.size() == 1 || (s.size() == 2 && (s[0] != goal[1] || s[1] != goal[0]))) return false;
        vector<int> v;
        bool chk_c = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
                v.push_back(i);
            
            chk[s[i]-'a']++;
            if (chk[s[i]-'a'] > 1) chk_c = 1;
        }
        if (v.empty() && chk_c) return true;
        if (v.size() != 2) return false;
        swap(s[v[0]], s[v[1]]);
        return (s == goal);
    }
};