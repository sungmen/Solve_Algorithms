/**
* Runtime: 156 ms, faster than 59.01% of C++ online submissions for Longest Harmonious Subsequence.
* Memory Usage: 41.6 MB, less than 38.97% of C++ online submissions for Longest Harmonious Subsequence.
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        for (auto i : nums) {
            if (m.find(i) == m.end()) {
                m[i] = 1;
            } else {
                m.find(i)->second++;
            }
        }
        int value = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (m.find(it->first + 1) != m.end()) {
                int tmp = it->second + m.find(it->first+1)->second;
                value = value < tmp ? tmp : value;
            }
        }
        return value;
    }
};