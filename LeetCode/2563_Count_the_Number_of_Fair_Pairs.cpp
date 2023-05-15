class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        long long ans = 0;
        while (l < r)
        {
            while (l < r && nums[l] + nums[r] > upper)
            {
                r--;
            }
            ans += (r - l);
            l++;
        }
        l = 0, r = nums.size() - 1;
        while (l < r)
        {
            while (l < r && nums[l] + nums[r] > lower - 1)
            {
                r--;
            }
            ans -= (r - l);
            l++;
        }
        return ans;
    }
};