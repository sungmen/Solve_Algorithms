/**
* Runtime: 4 ms, faster than 53.38% of C++ online submissions for Happy Number.
* Memory Usage: 6.3 MB, less than 42.91% of C++ online submissions for Happy Number.
*/

class Solution {
public:
    bool isHappy(int n) {
        map<int, int> m;
        while(n!=1) {
            if (m.find(n) == m.end()) {
                m[n] = 1;
            } else {
                return false;
            }
            int tmp = n;
            int res = 0;
            while(tmp != 0) {
                res += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            n = res;
        }
        return true;
    }
};