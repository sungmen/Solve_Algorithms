class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int, int> m;
        m[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < rooms[cur].size(); i++) {
                if (!m[rooms[cur][i]]) {
                    q.push(rooms[cur][i]);
                    m[rooms[cur][i]] = 1;
                }
            }
        }
        return (m.size() == rooms.size() ? true : false);        
    }
};