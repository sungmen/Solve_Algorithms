class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target)
        {
            return true;
        }
        
        for (int t = 0; t < 3; t++)
        {
            vector<vector<int>> next(mat.size(), vector<int>(mat[0].size(), 0));
            for (int i = 0; i < mat.size(); i++)
            {
                for (int j = 0; j < mat[0].size(); j++)
                {
                    next[i][j] = mat[mat.size()-1-j][i];
                }
            }
            if (next == target)
            {
                return true;
            }
            mat = next;
        }
        
        return false;
    }
};