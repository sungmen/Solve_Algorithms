class Solution 
{
public:
    vector<string> simplifiedFractions(int n) 
    {
        unordered_set<double> us;
        vector<string> ans;
        for (int i = 1; i < n; i++)
        {
            for (int j =  i + 1; j <= n; j++)
            {
                double d = (double)i / (double)j;
                if (us.find(d) == us.end())
                {
                    us.insert(d);
                    string str = "";
                    str+=to_string(i);
                    str+='/';
                    str+=to_string(j);
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};