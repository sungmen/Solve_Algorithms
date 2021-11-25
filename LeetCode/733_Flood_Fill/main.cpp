class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int changeColor = image[sr][sc];
        image[sr][sc] = newColor;
        int POS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                pair<int, int> next = {cur.first + POS[i][0], cur.second + POS[i][1]};
                if (next.first >= 0 && next.first < image.size() && next.second >= 0 && next.second < image[0].size() && changeColor == image[next.first][next.second]) {
                    q.push(next);
                    image[next.first][next.second] = newColor;
                }
            }
        }
        return image;
    }
};