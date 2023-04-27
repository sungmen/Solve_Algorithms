class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> v((n * 3) - 2, vector<int>((n * 3) - 2, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[n - 1 + i][n - 1 + j] = img1[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < (n * 2) - 1; i++)
        {
            for (int j = 0; j < (n * 2) - 1; j++)
            {
                int sum = 0;
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        if (v[i+k][j+l] == img2[k][l] && img2[k][l] == 1)
                        {
                            sum++;
                        }
                    }
                }
                cout << sum << '\n';
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};