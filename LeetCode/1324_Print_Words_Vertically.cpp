class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> res;
        int cur = 0;
        int col = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (' ' == s[i])
            {
                cur = 0;
                col++;
            }
            else
            {
                while (cur >= res.size())
                {
                    res.push_back("");
                }
                while (col > res[cur].size())
                {
                    res[cur] += ' ';
                }
                res[cur] += s[i];
                cur++;
            }
        }
        return res;
    }
};