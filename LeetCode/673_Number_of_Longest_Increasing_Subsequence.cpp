class Solution 
{
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        int len = 1, result = 0;
        vector<int> v(n, 1);
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] <= nums[j]) continue;
                if (v[j] + 1 > v[i])
                {
                    v[i] = v[j] + 1;
                    res[i] = res[j];
                }
                else if (v[j] + 1 == v[i])
                {
                    res[i] += res[j];
                }
            }
            if (len < v[i])
            {
                len = v[i];   
                result = 0;
            }
            if (len == v[i])
            {
                result += res[i];
            }
        }
        return result;
    }
};