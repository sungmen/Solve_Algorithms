class Solution 
{
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> v(26, 0);
        vector<int> chk(26, 0);
        int n = s.size();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            v[s[i]-'a'] = i;
        }
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            int idx = c - 'a';
            if (1 == chk[idx]) continue;
            while (! res.empty() && res.back() > c && v[res.back()-'a'] > i)
            {
                chk[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(c);
            chk[idx] = 1;
        }
        return res;
    }
};