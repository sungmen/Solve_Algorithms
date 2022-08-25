class Solution 
{
public:
    
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> res;
        int t = 1;
        for (auto tar : target)
        {
            while (tar >= t)
            {
                res.push_back("Push");
                if (tar != t)
                {
                    res.push_back("Pop");
                }
                t++;
            }
        }
        return res;
    }
};