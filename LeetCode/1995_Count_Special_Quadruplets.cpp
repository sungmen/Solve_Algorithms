class Solution 
{
public:
    int countQuadruplets(vector<int>& nums) 
    {
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < nums.size(); i++)
        {
            um[nums[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                for (int k = j + 1; k < nums.size() - 1; k++)
                {
                    int t = nums[i]+nums[j]+nums[k];
                    if (t)
                    {
                        vector<int> v = um[t];
                        for (int l = 0; l < v.size(); l++)
                        {
                            if (k < v[l])
                            {
                                ans += v.size() - l;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};