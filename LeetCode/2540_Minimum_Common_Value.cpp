class Solution 
{
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int, int> m;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (auto num : nums1)
            m[num]++;
        for (auto num : nums2)
        {
            if (m.find(num) != m.end())
                return num;
        }
        return -1;
    }
};