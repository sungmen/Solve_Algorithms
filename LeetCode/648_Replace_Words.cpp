class Solution 
{
private:
    unordered_map<string, int> um;
public:
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        string res = "";
        for (auto dic : dictionary)
        {
            um[dic] = 1;
        }
        string tmp = "";
        bool chk = 0;
        for (char sen : sentence)
        {
            if (' ' == sen)
            {
                if ("" != res) res += " ";
                res += tmp;
                tmp = "";
                chk = 0;
                continue;
            }
            if (!chk)
            {
                tmp += sen;
                if (um.find(tmp) != um.end())
                {
                    chk = 1;
                }
            }
        }
        if ("" != res) res += " ";
        res += tmp;
        return res;
    }
};