#include <queue>
#include <vector>
using namespace std;
struct th {
    int pos, y, x, cnt;
};
int v[2][101][101];
int solution(vector<vector<int>> board) {
    int n = board.size();
    v[0][0][0] = 1;
    queue<th> q;
    q.push({0, 0, 0, 0});
    while (!q.empty()) {
        th cur = q.front();
        q.pop();
        if ((cur.pos == 0 && cur.y == n - 1 && cur.x == n - 2) || (cur.pos == 1 && cur.y == n - 2 && cur.x == n - 1)) {
            return cur.cnt;
        }
        for (int i = 0; i < 8; i++) {
            if (cur.pos == 0) {
                switch(i) {
                    case 0: {
                        th next = {cur.pos, cur.y - 1, cur.x, cur.cnt + 1};
                        if (next.y >= 0 && next.y < n && next.x >= 0 && next.x+1 < n && !v[0][next.y][next.x] && !board[next.y][next.x] && !board[next.y][next.x+1]) {
                            v[0][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 1: {
                        th next = {cur.pos, cur.y, cur.x - 1, cur.cnt + 1};
                        if (next.y >= 0 && next.y < n && next.x >= 0 && next.x < n && !v[0][next.y][next.x] && !board[next.y][next.x]) {
                            v[0][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 2: {
                        th next = {cur.pos, cur.y + 1, cur.x, cur.cnt + 1};
                        if (next.y >= 0 && next.y < n && next.x >= 0 && next.x+1 < n && !v[0][next.y][next.x] && !board[next.y][next.x] && !board[next.y][next.x+1]) {
                            v[0][next.y][next.x]=1;
                            q.push(next);
                        }                        
                        break;
                    }
                    case 3: {
                        th next = {cur.pos, cur.y, cur.x + 1, cur.cnt + 1};
                        if (next.y >= 0 && next.y < n && next.x >= 0 && next.x+1 < n && !v[0][next.y][next.x] && !board[next.y][next.x+1]) {
                            v[0][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 4: {
                        th next = {1, cur.y - 1, cur.x, cur.cnt + 1};
                        if (next.y >= 0 && next.y < n && next.x >= 0 && next.x+1 < n && !v[1][next.y][next.x] && !board[next.y][next.x] && !board[next.y][next.x+1]) {
                            v[1][next.y][next.x] = 1;
                            q.push(next);
                        }                        
                        break;
                    }
                    case 5: {
                        th next = {1, cur.y - 1, cur.x + 1, cur.cnt + 1};
                        if (next.y >= 0 && next.y < n && next.x-1 >= 0 && next.x < n && !v[1][next.y][next.x] && !board[next.y][next.x] && !board[next.y][next.x-1]) {
                            v[1][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 6: {
                        th next = {1, cur.y, cur.x, cur.cnt + 1};
                        if (next.y >= 0 && next.y+1 < n && next.x >= 0 && next.x+1 < n && !v[1][next.y][next.x] && !board[next.y+1][next.x] && !board[next.y+1][next.x+1]) {
                            v[1][next.y][next.x] = 1;
                            q.push(next);
                        }                        
                        break;
                    }
                    case 7: {
                        th next = {1, cur.y, cur.x+1, cur.cnt + 1};
                        if (next.y >= 0 && next.y+1 < n && next.x-1 >= 0 && next.x < n && !v[1][next.y][next.x] && !board[next.y+1][next.x] && !board[next.y+1][next.x-1]) {
                            v[1][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                }
            } else {
                switch(i) {
                    case 0: {
                        th next = {cur.pos, cur.y - 1, cur.x, cur.cnt + 1};
                        if (next.y >= 0 && next.y < n && next.x >= 0 && next.x < n && !v[1][next.y][next.x] && !board[next.y][next.x]) {
                            v[1][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 1: {
                        th next = {cur.pos, cur.y, cur.x+1, cur.cnt + 1};
                        if (next.y >= 0 && next.y+1 < n && next.x >= 0 && next.x < n && !v[1][next.y][next.x] && !board[next.y][next.x] && !board[next.y+1][next.x]) {
                            v[1][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 2: {
                        th next = {cur.pos, cur.y, cur.x-1, cur.cnt + 1};
                        if (next.y >= 0 && next.y+1 < n && next.x >= 0 && next.x < n && !v[1][next.y][next.x] && !board[next.y][next.x] && !board[next.y+1][next.x]) {
                            v[1][next.y][next.x] = 1;
                            q.push(next);
                        }                        
                        break;
                    }
                    case 3: {
                        th next = {cur.pos, cur.y + 1, cur.x, cur.cnt + 1};
                        if (next.y >= 0 && next.y+1 < n && next.x >= 0 && next.x < n && !v[1][next.y][next.x] && !board[next.y+1][next.x]) {
                            v[1][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 4: {
                        th next = {0, cur.y, cur.x-1, cur.cnt + 1};
                        if (next.y >= 0 && next.y+1 < n && next.x >= 0 && next.x < n && !v[0][next.y][next.x] && !board[next.y][next.x] && !board[next.y+1][next.x]) {
                            v[0][next.y][next.x] = 1;
                            q.push(next);
                        }                        
                        break;
                    }
                    case 5: {
                        th next = {0, cur.y, cur.x, cur.cnt + 1};
                        if (next.y >= 0 && next.y+1 < n && next.x >= 0 && next.x+1 < n && !v[0][next.y][next.x] && !board[next.y][next.x+1] && !board[next.y+1][next.x+1]) {
                            v[0][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 6: {
                        th next = {0, cur.y+1, cur.x-1, cur.cnt + 1};
                        if (next.y-1 >= 0 && next.y < n && next.x >= 0 && next.x < n && !v[0][next.y][next.x] && !board[next.y][next.x] && !board[next.y-1][next.x]) {
                            v[0][next.y][next.x] = 1;
                            q.push(next);
                        }                        
                        break;
                    }
                    case 7: {
                        th next = {0, cur.y+1, cur.x, cur.cnt + 1};
                        if (next.y-1 >= 0 && next.y < n && next.x+1 >= 0 && next.x+1 < n && !v[0][next.y][next.x] && !board[next.y][next.x+1] && !board[next.y-1][next.x+1]) {
                            v[0][next.y][next.x] = 1;
                            q.push(next);
                        }
                        break;
                    }
                }               
            }
        }
    }
    return -1;
}