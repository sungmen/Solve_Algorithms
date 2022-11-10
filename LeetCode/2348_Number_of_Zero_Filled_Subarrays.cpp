class Solution {
public
    long long zeroFilledSubarray(vectorint& nums) {
        long long res = 0;
        int t = 0;
        for (auto num  nums) {
            if (0 == num)
                res += (++t);
            else
                t = 0;
        }
        return res;
    }
};