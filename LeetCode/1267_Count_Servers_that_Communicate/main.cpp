class Solution {    
public:
    int countServers(vector<vector<int>>& grid) {
        map<pair<int, int>, int> pos;
        map<int, vector<pair<int, int>>> row, col;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    pos[{i, j}] = 1;
                    if (row.find(i) != row.end()) {
                        row[i].push_back({i, j});
                    } else {
                        row[i] = vector<pair<int, int>>();
                        row[i].push_back({i, j});
                    }
                    if (col.find(j) != col.end()) {
                        col[j].push_back({i, j});
                    } else {
                        col[j] = vector<pair<int, int>>();
                        col[j].push_back({i, j});
                    }
                }
            }
        }
        int res = 0;
        for (auto it = pos.begin(); it != pos.end(); ++it) {
            if (it->second == 1) {
                queue<pair<int, int>> q;
                it->second = 2;
                q.emplace(it->first);
                int tmp = 1;
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int i = 0; i < row[cur.first].size(); ++i) {
                        if (pos[row[cur.first][i]]==1) {
                            pos[row[cur.first][i]] = 2;
                            tmp++;
                            q.emplace(row[cur.first][i]);
                        }
                    }
                    for (int i = 0; i < col[cur.second].size(); ++i) {
                        if (pos[col[cur.second][i]]==1) {
                            pos[col[cur.second][i]] = 2;
                            tmp++;
                            q.emplace(col[cur.second][i]);
                        }
                    }
                }
                if (tmp > 1) res += tmp;
            }
        }
        return res;
    }
};