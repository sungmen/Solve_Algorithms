class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        if(nums.size() < 3) return v;
        sort(nums.begin(), nums.end());        
        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    v.push_back({nums[i], nums[l], nums[r]});
                    int templ = nums[l];
                    int tempr = nums[r];
                    while(l < r && nums[l] == templ) {
                        l++;
                    }
                    while(l < r && nums[r] == tempr) {
                        r--;
                    }
                }
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;   
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
        }
        return v;
    }
};