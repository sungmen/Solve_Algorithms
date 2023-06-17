class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int n = nums.size();
       int result = 0;
       for (int i = 2; i < n; i++)
       {
           int l = 0, r = i - 1;
           while (l < r)
           {
               if (nums[l] + nums[r] - nums[i] > 0)
               {
                   result += (r - l);
                   r --;
               }
               else
               {
                   l++;
               }
           }
       }
       return result;
    }
};