class Solution 
{
public:

    vector<string> changeSlashToDot(const int n, vector<string> vec)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vec[i][j] == '-')
                {
                    vec[i][j] = '.';
                }
            }
        }
        return vec;
    }

    void makeChess(const int n, const int r, const int c, vector<string> vec, vector<vector<string>> &answer)
    {
        if (n == r + 1)
        {
            answer.push_back(changeSlashToDot(n, vec));
            return;
        }

        int r1 = r + 1;
        int c1 = c;
        while (r1 < n && c1 < n) vec[r1++][c1] = '-';
        int r2 = r + 1;
        int c2 = c + 1;
        while (r2 < n && c2 < n) vec[r2++][c2++] = '-';
        int r3 = r + 1;
        int c3 = c - 1;
        while (r3 < n && c3 >= 0) vec[r3++][c3--] = '-';
        for (int i = 0; i < n; i++)
        {
            if (vec[r + 1][i] != '-')
            {
                vec[r + 1][i] = 'Q';
                makeChess(n, r + 1, i, vec, answer);
                vec[r + 1][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> answer;
        string strChess(n, '.');
        vector<string> vec(n, strChess);
        for (int i = 0; i < n; i++)
        {
            vec[0][i] = 'Q';
            makeChess(n, 0, i, vec, answer);
            vec[0][i] = '.';
        }
        return answer;
    }
};