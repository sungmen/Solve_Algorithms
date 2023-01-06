class Solution 
{
private:
    unordered_map<string, int> um;
    vector<string> res;

public:
    void check(string name)
    {
        if (um.find(name) == um.end())
        {
            um[name] = 1;
            res.push_back(name);
            return;
        }
        while (true)
        {
            string add = "(" + to_string(um[name]) + ")";
            ++um[name];
            if (um.find(name + add) == um.end())
            {
                um[name + add] = 1;
                res.push_back(name + add);
                return;
            }
        }
    }

    vector<string> getFolderNames(vector<string>& names) 
    {
        for (auto name : names)
        {
            check (name);
        }
        return res;
    }
};