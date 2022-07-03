class Solution {
public:
    struct node {
        vector<vector<bool>> check;
        pair<int, int> poi;
        int cnt = 0;
    };
    
    const int pos[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> chk(m ,vector<bool>(n, false));
        int everyObj = m * n;
        pair<int, int> pstart, goal;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    chk[i][j] = true;
                    --everyObj;
                } else if (grid[i][j] == 1) {
                    pstart = {i, j};
                    chk[i][j] = true;
                } else if (grid[i][j] == 2) {
                    goal = {i, j};
                }
            }
        }
        queue<node> q;
        q.push({chk, pstart, 1});
        int answer = 0;
        while (!q.empty()) {
            node p = q.front();
            q.pop();
            if (p.poi == goal && p.cnt != everyObj) continue;
            if (p.cnt == everyObj) {
                if (p.poi == goal) {
                    answer++;
                }
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                pair<int, int> next = {p.poi.first + pos[i][0], p.poi.second + pos[i][1]};
                if (next.first >= 0 && next.first < m && next.second >= 0 && next.second < n && !p.check[next.first][next.second]) {
                    vector<vector<bool>> tmpchk = p.check;
                    tmpchk[next.first][next.second] = 1;
                    q.push({tmpchk, next, p.cnt + 1});
                }
            }
        }
        return answer;
    }
};