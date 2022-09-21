class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!(nums[i] % 2))
            {
                result += nums[i];
            }
        }
        
        for (auto querie : queries)
        {
            int t = nums[querie[1]] + querie[0];
            if (!(nums[querie[1]] % 2))
            {
                result -= nums[querie[1]];
                if (!(t % 2))
                {
                    result += t;
                }
            }
            else
            {
                if (!(t % 2))
                {
                    result += t;
                }                
            }
            res.push_back(result);
            nums[querie[1]] = t;
        }
        
        return res;
    }
};