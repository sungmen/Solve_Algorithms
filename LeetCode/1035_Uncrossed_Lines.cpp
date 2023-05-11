class Solution 
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    v[i][j] = (i == 0 || j == 0)? 1 : v[i-1][j-1] + 1;
                }
                else
                {
                    v[i][j] = max((i == 0 ? 0 : v[i-1][j]), (j == 0 ? 0 : v[i][j-1]));
                }
            }
        }
        return v[n-1][m-1];
    }
};