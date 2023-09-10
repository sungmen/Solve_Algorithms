class Solution 
{
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_map<string, int> um;
        for (auto it : emails)
        {
            bool sign = false;
            bool ignore = false;
            string str = "";
            for (auto i : it)
            {
                if (i == '@') sign = true;
                if (sign == false)
                {
                    if (i == '+') ignore = true;
                    if (i == '.' || ignore) continue;
                }
                str += i;
            }
            um[str]++;
        }
        return um.size();
    }
};