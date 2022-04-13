struct th {
    int y, x;  
};
class Solution {
public:
    map<char, pair<int, int>> m;
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        m['L'] = {0, -1};
        m['R'] = {0, 1};
        m['U'] = {-1, 0};
        m['D'] = {1, 0};
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            string tmp = s.substr(i);
            queue<th> q;
            q.push({startPos[0], startPos[1]});
            int cnt = 0;
            while (!q.empty()) {
                th cur = q.front();
                q.pop();
                int ny = m[tmp[cnt]].first, nx = m[tmp[cnt]].second;
                if (cnt < tmp.size() && n > ny + cur.y && n > nx + cur.x && 0 <= ny + cur.y && 0 <= nx + cur.x) {
                    q.push({ny + cur.y, nx + cur.x});
                    cnt++;
                } else {
                    ans.push_back(cnt);
                    break;
                }
            }
        }
        return ans;
    }
};