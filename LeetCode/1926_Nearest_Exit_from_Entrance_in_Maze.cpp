class Solution {
public:
    struct th {
        int y, x, cnt;
    };
    bool check(int y, int x, int m, int n, vector<vector<char>>& maze) {
        if (y < 0 || y >= m ||x < 0 || x >= n || '+' == maze[y][x]) {
            return false;
        }
        maze[y][x] = '+';
        return true;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        map<pair<int, int>, int> chk;
        int m = maze.size(), n = maze[0].size();
        maze[entrance[0]][entrance[1]] = '+';
        queue<th> q;
        q.push({entrance[0], entrance[1], 0});
        while (!q.empty()) {
            th cur = q.front();
            q.pop();
            if ((cur.y == 0 || cur.y == m - 1 || cur.x == 0 || cur.x == n - 1) && false == (cur.y == entrance[0] && cur.x == entrance[1])) {
                return cur.cnt;
            }
            th next = {cur.y + 1, cur.x, cur.cnt + 1};
            if (check(next.y, next.x, m, n, maze)) {
                q.push(next);
            }
            next.y = cur.y - 1;
            if (check(next.y, next.x, m, n, maze)) {
                q.push(next);
            }
            next.y = cur.y;
            next.x = cur.x + 1;
            if (check(next.y, next.x, m, n, maze)) {
                q.push(next);
            }
            next.x = cur.x - 1;
            if (check(next.y, next.x, m, n, maze)) {
                q.push(next);
            }
        }

        return -1;
    }
};