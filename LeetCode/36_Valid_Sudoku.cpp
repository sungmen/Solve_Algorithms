class Solution {
private:
    map<int, int> posY[9], posX[9];
    map<pair<int, int>, int> posYX[9];
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int c = board[i][j] - '1';
                    if (posY[c][i]) {
                        return false;
                    } else {
                        posY[c][i] = 1;
                    }
                    if (posX[c][j]) {
                        return false;
                    } else {
                        posX[c][j] = 1;
                    }
                    if (posYX[c][{i/3, j/3}]) {
                        return false;
                    } else {
                        posYX[c][{i/3, j/3}] = 1;
                    }
                }
            }
        }
        return true;
    }
};