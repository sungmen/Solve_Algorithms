class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int i = 0, j = 0;
        while(j < nums.size()) 
        {
            if (!nums[j++]) k--;
            if (k < 0 && !nums[i++]) k++;
        }
        
        return j - i;
    }
};