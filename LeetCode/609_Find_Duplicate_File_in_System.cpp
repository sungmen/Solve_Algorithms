class Solution 
{
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> um;
        for (auto path : paths)
        {
            stringstream ss(path);
            string str;
            string dic = "";
            while(getline(ss, str, ' '))
            {
                if (dic == "")
                {
                    dic = str;
                }
                else
                {
                    int ustr = str.find('(');
                    um[str.substr(ustr+1, str.size() - 2 - ustr)].push_back(dic + '/' + str.substr(0, ustr));
                }
            }
        }
        
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second.size() < 2)
            {
                continue;
            }
            vector<string> vs;
            for (auto v : it->second)
            {
                vs.push_back(v);
            }
            res.push_back(vs);
        }
        
        return res;
    }
};