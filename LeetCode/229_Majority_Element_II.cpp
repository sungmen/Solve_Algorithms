class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int t = nums.size() / 3;
        vector<int> res;
        unordered_map<int, int> um, p;
        for (auto i : nums)
        {
            um[i]++;
        }
        for (auto i : nums)
        {
            if ((!res.empty() && res.back() == i) || p.find(i) != p.end()) continue;
            if (um[i] > t) res.push_back(i);
            p[i]++;
            um[i]--;
        }
        return res;
    }
};