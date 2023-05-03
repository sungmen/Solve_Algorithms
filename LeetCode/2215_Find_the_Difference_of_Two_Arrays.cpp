class Solution 
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> um, um2;
        set<int> s, s2;
        for (auto num : nums1)    
        {
            s.insert(num);
        }
        for (auto it = s.begin(); it != s.end(); it++)
        {
            um[*it] = 1;
        }
        for (auto num : nums2)
        {
            s2.insert(num);
        }
        vector<int> a1, a2;
        for (auto it = s2.begin(); it != s2.end(); it++)
        {
            if (um.find(*it) != um.end())
                um.erase(*it);
            else
                a2.push_back(*it);
        }
        for (auto it = um.begin(); it != um.end(); it++)
        {
            a1.push_back(it->first);
        }
        return {a1, a2};
    }
};