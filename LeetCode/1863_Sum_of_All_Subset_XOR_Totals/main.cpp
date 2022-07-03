class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> v;
        v.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            int vSize = v.size();
            for (int j = 0; j < vSize; j++) {
                if (j == 0) v.push_back(nums[i]);
                else {
                    v.push_back(v[j] ^ nums[i]);
                }
            }       
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};