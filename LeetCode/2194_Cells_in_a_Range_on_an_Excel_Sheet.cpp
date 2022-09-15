class Solution 
{
public:
    vector<string> cellsInRange(string s) 
    {
        vector<string> res;
        for (int i = s[0] - 'A'; i <= s[3] - 'A'; i++)
        {
            for (int j = s[1] - '0'; j <= s[4] - '0'; j++)
            {
                string tmp = "";
                tmp += (char)(i + 'A');
                tmp += (char)(j + '0');
                res.push_back(tmp);
            }
        }
        
        return res;
    }
};