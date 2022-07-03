class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size(), m = nums2.size();
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    if (i > 0 && j > 0) {
                        arr[i][j] = 1 + arr[i-1][j-1];
                    } else {
                        arr[i][j] = 1;
                    }
                    ans = max(ans, arr[i][j]);
                }
            }
        }
        return ans;
    }
};