class Solution 
{
public:
    unordered_map<int, vector<int>> um;
    vector<vector<string>> res;
    void dfs(int index, vector<string> v, string &s)
    {
        if (index == s.size())
        {   
            res.push_back(v);
            return;
        }
        for (auto it : um[index])
        {
            string r = s.substr(index, it - index + 1);
            v.push_back(r);
            dfs(it + 1, v, s);
            v.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                string str = s.substr(i, j - i + 1);
                string rev = str;
                reverse(rev.begin(), rev.end());
                if (rev == str)
                    um[i].push_back(j);
            }
        }
        dfs(0, {}, s);
        return res;
    }
};