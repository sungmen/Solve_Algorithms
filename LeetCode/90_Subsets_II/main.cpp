class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v = {{}};
        sort(nums.begin(), nums.end());
        map<vector<int>, int> um; 
        for(auto n : nums) {
            int s = v.size();
            for (int i = 0; i < s; i++) {
                vector<int> tmp = v[i];
                tmp.push_back(n);
                if (!um[tmp]) {
                    v.push_back(tmp);
                    um[tmp] = 1;
                }
            }
        }
        
        return v;
    }
};