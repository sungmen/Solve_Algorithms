class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string, int> um;
        for (int i = 0; i < list1.size(); i++)
        {
            um[list1[i]] = i;
        }
        int res = 1e9;
        vector<string> v;
        for (int i = 0; i < list2.size(); i++)
        {
            if (um.find(list2[i]) != um.end() && res >= (um[list2[i]] + i))
            {
                if (res == um[list2[i]] + i)
                {
                    v.push_back(list2[i]);
                }
                else
                {
                    res = um[list2[i]] + i;
                    v.clear();
                    v.push_back(list2[i]);
                }
            }
        }
        return v;
    }
};