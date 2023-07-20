class Solution 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
        int res = -1;
        int lar = -1;
        int second = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lar < nums[i])
            {
                second = lar;
                lar = nums[i];
                res = i;
            }
            else if (second < nums[i])
            {
                second = nums[i];
            }
        }

        return (lar >= 2 * second ? res : -1);
    }
};