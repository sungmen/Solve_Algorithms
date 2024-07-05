class Solution 
{
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) 
    {
        vector<int> ans;
        vector<int> stk;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            if (x != nums[idx]) { continue; }
            stk.push_back(idx);
        }
        for (auto q : queries)
        {
            if (q > stk.size()) { 
                ans.push_back(-1);
                continue;
            }
            ans.push_back(stk[q-1]);
        }
        return ans;
    }
};