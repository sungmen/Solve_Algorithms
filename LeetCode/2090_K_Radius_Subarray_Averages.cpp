class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) return nums;
        int n = nums.size();
        vector<int> v(n, -1);
        if (n < k) return v;
        int m = k * 2 + 1;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (i < m - 1) continue;
            if (i != m - 1) sum -= nums[i - m];
            int div = sum / (m);
            v[i - k] = div;
        }
        return v;
    }
};