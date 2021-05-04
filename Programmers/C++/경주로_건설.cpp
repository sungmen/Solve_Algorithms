#include <bits/stdc++.h>
using namespace std;
const int POS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
struct dic {
    int y, x, d, cost;
};
int solution(vector<vector<int>> board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> chk(m, vector<int>(n, 1000000));
    queue<dic> q;
    chk[0][0] = 0;
    q.push({0, 0, 0, 0});
    q.push({0, 0, 2, 0});
    while(!q.empty()) {
        dic cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            dic next = {cur.y+POS[i][0], cur.x+POS[i][1], i, cur.cost+100};
            if (cur.d != i) next.cost+=500;
            if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n || board[next.y][next.x] == 1 || chk[next.y][next.x] < next.cost) continue;
            chk[next.y][next.x] = next.cost;
            q.push(next);
        }
    }
    return chk[m-1][n-1];
}