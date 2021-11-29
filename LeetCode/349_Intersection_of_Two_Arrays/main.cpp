class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for (auto i : nums1) {
            m[i] = 1;
        }
        vector<int> ans;
        set<int> s;
        for (auto i : nums2) {
            s.insert(i);
        }
        for (auto i : s) {
            if (m.find(i) != m.end()) ans.push_back(i);
        }
        return ans;
    }
};
