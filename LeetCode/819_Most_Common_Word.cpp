class Solution 
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        unordered_map<string, int> um;
        unordered_map<string, int> ban;
        for (auto b : banned) ban[b]++;
        string tmp = "";
        string res = "";
        int cnt = 0;
        paragraph += ' ';
        for (auto it : paragraph)
        {
            if (it == ' ' || it == '!' || it == '?' || it == '\'' || it == ',' || it == ';' || it == '.')
            {
                if (tmp == "")continue;
                if (ban.find(tmp) != ban.end())
                {
                    tmp = "";
                    continue;
                }
                um[tmp]++;
                if (um[tmp] > cnt)
                {
                    res = tmp;
                    cnt = um[tmp];
                }
                cout << tmp << ' ';
                tmp = "";
            }
            else
            {
                tmp += tolower(it);
            }
        }
        return res;
    }
};