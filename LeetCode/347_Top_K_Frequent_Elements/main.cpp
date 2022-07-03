/**
* Runtime: 44 ms, faster than 15.17% of C++ online submissions for Top K Frequent Elements.
* Memory Usage: 14.2 MB, less than 58.05% of C++ online submissions for Top K Frequent Elements.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                m.find(nums[i])->second++;
            } else {
                m[nums[i]] = 1;
            }
        }
        vector<pair<int, int>> res;
        copy(m.begin(), m.end(), back_inserter(res));
        sort(res.begin(), res.end(), [](const pair<int, int>& l, const pair<int, int>& r) {if (l.second != r.second) return l.second > r.second; return l.first > r.first;});
        int i = 0;
        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(res[i].first);
        return ans;
    }
};