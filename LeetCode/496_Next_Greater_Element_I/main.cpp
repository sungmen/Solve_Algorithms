/**
* Runtime: 4 ms, faster than 99.60% of C++ online submissions for Next Greater Element I.
* Memory Usage: 9.1 MB, less than 80.71% of C++ online submissions for Next Greater Element I.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) return {};
        vector<pair<int, int>> num(nums2.size());
        num[nums2.size()-1] = {nums2[nums2.size()-1], -1};
        stack<int> stk;
        stk.push(nums2[nums2.size() - 1]);
        for (int i = nums2.size() - 2; i >= 0; i--) {
            while(!stk.empty() && nums2[i] > stk.top()) stk.pop();
            if (!stk.empty()) {
                num[i] = {nums2[i], stk.top()};
                stk.push(nums2[i]);
            } else {
                num[i] = {nums2[i], -1};
                stk.push(nums2[i]);
            }
        }
        sort(num.begin(), num.end());
        for(int i = 0; i < nums1.size(); i++) {
            int begin = 0;
            int end = num.size();
            while(begin < end) {
                int mid = (begin + end) / 2;
                if (num[mid].first == nums1[i]) {
                    nums1[i] = num[mid].second;
                    break;
                } else if (num[mid].first > nums1[i]) {
                    end = mid;
                } else if (num[mid].first < nums1[i]) {
                    begin = mid + 1;
                }
            }            
        }
        return nums1;
    }
};