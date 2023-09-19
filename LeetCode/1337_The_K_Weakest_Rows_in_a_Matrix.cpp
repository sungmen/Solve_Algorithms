class Solution 
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<vector<int>> res(mat.size(), vector<int>(2, 0));
        for (int i = 0; i < mat.size(); i++)
        {
            res[i][1] = i;
            for (auto j : mat[i])
            {
                res[i][0] += j;
            }
        }

        sort(res.begin(), res.end());
        vector<int> answer(k);
        for (int i = 0; i < k; i++)answer[i]=res[i][1];
        return answer;
    }
};