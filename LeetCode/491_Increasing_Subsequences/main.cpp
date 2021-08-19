class Solution {
private:
    set<vector<int>> s;
    vector<int> nums;
    
public:
    void dfs(vector<int> r, int index) {
        if (r.size() > 1) {
            s.insert(r);
        }
        for (int i = index + 1; i < nums.size(); ++i) {
            if (nums[index] <= nums[i]) {
                vector<int> tmp = r;
                tmp.push_back(nums[i]);
                dfs(tmp, i);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->nums = nums;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> v;
            v.push_back(nums[i]);
            dfs(v, i);
        }
        vector<vector<int>> res;
        for (auto it = s.begin(); it != s.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }
};