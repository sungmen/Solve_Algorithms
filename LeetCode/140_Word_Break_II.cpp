class Solution {
private:

    vector<string> res;
    map<string, int> m;

public:

    void dfs(string s, int idx, string result)
    {
        if (idx == s.size())
        {
            res.push_back(result);
        }


        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (s.substr(idx, it->first.size()) == it->first)
            {
                string nexttmp = result;
                if (result != "")
                    nexttmp += " ";
                nexttmp += it->first;
                dfs(s, idx + it->first.size(), nexttmp);
            }
        }

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        for (auto str : wordDict)
            m[str] = 1;

        dfs(s, 0, "");

        return res;
    }

};