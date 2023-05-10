class Solution 
{
public:
    const int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) 
    {
        int moveCnt = 1;
        int moveCal = 0;
        int cnt = 0;
        int cntCal = 0;
        int cntBlock = 0;
        int allCnt = rows * cols;
        vector<vector<int>> ans;
        int y = rStart;
        int x = cStart;
        while (cntBlock < allCnt)
        {
            if (y >= 0 && y < rows && x >= 0 && x < cols)
            {
                cntBlock++;
                ans.push_back({y, x});
            }
            y += pos[moveCal][0];
            x += pos[moveCal][1];
            cnt++;
            if (moveCnt == cnt)
            {
                cntCal++;
                cnt = 0;
                moveCal++;
                moveCal %= 4;
            }
            if (cntCal == 2)
            {
                moveCnt++;
                cntCal = 0;
            }

        }
        return ans;
    }
};