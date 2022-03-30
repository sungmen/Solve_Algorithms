class Solution {
private:
    map<int, int> posy[101], posx[101];
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (posy[matrix[i][j]][i]) {
                    return false;
                } else {
                    posy[matrix[i][j]][i] = 1;
                }
                if (posx[matrix[i][j]][j]) {
                    return false;
                } else {
                    posx[matrix[i][j]][j] = 1;
                }
            }
        }
        return true;
    }
};