class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 2; i < n; i++)
        {
            int l = 0, r = i - 1, m = 0;
            for ( ; l < r; )
            {
                m = arr[l] + arr[r];
                if (m < arr[i])
                {
                    l++;
                }
                else if (m > arr[i])
                {
                    r--;
                }
                else
                {
                    v[r][i] = v[l][r] + 1;
                    res = max(res, v[r][i]);
                    l++, r--;
                }
            }
        }
        return (0 == res ? 0 : res + 2);
    }
};