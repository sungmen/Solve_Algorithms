class Solution 
{
public:
    unordered_map<string, int> um;
    int res = 0;
    string s_;
    
    void dfs(int idx)
    {
        if (idx == s_.size())
        {
            if (res < um.size())
            {
                res = um.size();
            }
            return;
        }
        string str = "";
        for (int i = idx; i < s_.size(); i++)
        {
            str += s_[i];
            if (um.find(str) == um.end())
            {
                um[str] = 1;
                dfs(i + 1);
                um.erase(str);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        s_ = s;
        dfs(0);
        return res;
    }
};