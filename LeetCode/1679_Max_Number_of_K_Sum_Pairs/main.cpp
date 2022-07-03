/**
* Runtime: 324 ms, faster than 86.20% of C++ online submissions for Max Number of K-Sum Pairs.
* Memory Usage: 68.2 MB, less than 42.80% of C++ online submissions for Max Number of K-Sum Pairs.
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto i : nums) {
            if (m.find(i) != m.end()) m.find(i)->second++;
            else m[i] = 1;
        }
        int ans = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (k % 2) {
                if(it->first <= k/2) {
                    int tmp = k - it->first;
                    int tc = it->second < m.find(tmp)->second ? it->second : m.find(tmp)->second;
                    ans += tc;
                }
            } else {
                if (it->first == k/2) {
                    int tc = it->second / 2;
                    ans += tc;
                } else if (it->first < k/2) {
                    int tmp = k - it->first;
                    int tc = it->second < m.find(tmp)->second ? it->second : m.find(tmp)->second;
                    ans += tc;
                }
            }
        }
        return ans;
    }
};