class Solution 
{
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        vector<int> odd, even;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2)
            {
                even.push_back(-nums[i]);
            }
            else
            {
                odd.push_back(nums[i]);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i%2)
            {
                nums[i] = -even[i/2];
            }
            else
            {
                nums[i] = odd[i/2];
            }
        }

        return nums;
    }
};