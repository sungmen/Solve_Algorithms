class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd, even, res;
        for (auto n : nums) {
            if (n%2) even.push_back(n);
            else odd.push_back(n);
        }
        for (int i = 0; i < even.size(); ++i) {
            res.push_back(odd[i]);
            res.push_back(even[i]);
        }
        return res;
    }
};