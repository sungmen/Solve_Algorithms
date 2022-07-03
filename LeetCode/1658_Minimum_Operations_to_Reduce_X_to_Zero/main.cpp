/**
* Runtime: 728 ms, faster than 45.88% of C++ online submissions for Minimum Operations to Reduce X to Zero.
* Memory Usage: 196.8 MB, less than 6.52% of C++ online submissions for Minimum Operations to Reduce X to Zero.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int, int> cl, cr;
        bool cntl = false, cntr = false;
        if (nums[0] <= x) {
            cntl = true;
            cl[0] = 0;
            cl[nums.front()] = 1;
            int sum = nums.front();
            for (int i = 1; i < nums.size(); i++) {
                if(sum + nums[i] <= x) {
                    sum += nums[i];
                    cl[sum] = i + 1;
                } else {
                    break;
                }
            }
        }
        if (nums[nums.size() - 1] <= x) {
            cntr = true;
            cr[0] = 0;
            cr[nums.back()] = 1;
            int sum = nums.back();
            int cnt = 1;
            for (int i = nums.size() - 2; i >= 0; i--) {
                if (sum + nums[i] <= x) {
                    sum += nums[i];
                    cr[sum] = ++cnt;
                } else {
                    break;
                }
            }
        }
        if (cntl == false && cntr == false) return -1;
        else if (cntr == false) {
            if(cl.find(x) != cl.end()) return cl.find(x)->second;
            else return -1;
        } else if (cntl == false) {
            if(cr.find(x) != cr.end()) return cr.find(x)->second;
            else return -1;
        } else {
            int res = 1e9+1;
            for (map<int, int>::iterator it = cl.begin(); it != cl.end(); ++it) {
                if (cr.find(x - it->first) != cr.end()) {
                    int tmp = it->second + cr.find(x - it->first)->second;
                    if (res > tmp && tmp <= nums.size()) res = tmp;
                }
            }
            return res != 1e9+1 ? res : -1;
        }
    }
};