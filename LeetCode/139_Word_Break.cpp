class Solution 
{
private:
    bool arr[301];
    map<string, int> m;

public:
    void init(vector<string>& wordDict)
    {
        memset(arr, false, sizeof(arr));
        for (auto str : wordDict)
            m[str] = 1;
        arr[0] = true;
    }

    void check(string &s, int idx)
    {
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (s.size() >= it->first.size() + idx && s.substr(idx, it->first.size()) == it->first)
            {
                arr[idx + it->first.size()] = 1;
            }
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        init(wordDict);

        for (int i = 0; i < s.size(); i++)
        {
            if (true == arr[i])
            {
                check(s, i);
            }
        }
        
        return arr[s.size()];
    }

};