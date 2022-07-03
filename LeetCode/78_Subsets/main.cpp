/**
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
* Memory Usage: 7.2 MB, less than 90.31% of C++ online submissions for Subsets.
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v = {{}};
        for (auto i : nums) {
            int SIZE = v.size();
            for (int j = 0; j < SIZE; j++) {
                vector<int> tmp = v[j];
                tmp.push_back(i);
                v.push_back(tmp);
            }
        }
        return v;
    }
};