class Solution {
public:
    const int POS[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
    
    struct th { 
        int x;
        int y;
        int cnt;
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        int r = grid.size();
        int c = grid[0].size();
        queue<th> q;
        q.push({0, 0, 1});
        map<pair<int, int>, int> um;
        um[{0, 0}] = 1;
        while(!q.empty()) {
            th cur = q.front();
            if (cur.x == r-1 && cur.y == c-1) return cur.cnt;
            q.pop();
            for (int i = 0; i < 8; i++) {
                th next = {cur.x + POS[i][0], cur.y + POS[i][1], cur.cnt + 1};
                if (next.x < 0 || next.x >= r || next.y < 0 || next.y >= c || um[{next.x, next.y}] || grid[next.x][next.y]) continue;
                um[{next.x, next.y}] = 1;
                q.push(next);
            }
        }
        return -1;
    }
};