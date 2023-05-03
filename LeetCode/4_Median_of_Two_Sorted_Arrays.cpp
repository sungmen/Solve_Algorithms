class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int idx = 0, idx2 = 0;
        int m = nums1.size(), m2 = nums2.size();
        int k = (m + m2) / 2;
        int b = !((m + m2) % 2);
        int cnt = 0;
        double ans = 0;
        while ((m > idx || m2 > idx2) && cnt <= k)
        {
            double cur = 0;
            if (m == idx)
            {
                cur = nums2[idx2++];
            }
            else if (m2 == idx2)
            {
                cur = nums1[idx++];
            }
            else
            {
                if (nums1[idx] < nums2[idx2])
                {
                    cur = nums1[idx++];
                }
                else
                {
                    cur = nums2[idx2++];
                }
            }
            if (b && (cnt == k - 1 || cnt == k))
            {
                ans += cur;
                if (cnt == k)
                    ans /= 2;
            }
            else if (cnt == k)
            {
                ans += cur;
            }
            cnt++;
        }
        return ans;
    }
};