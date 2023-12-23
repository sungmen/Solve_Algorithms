class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    int pos[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0},
                     {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
    for (int i = 0; i < img.size(); i++) {
      for (int j = 0; j < img[i].size(); j++) {
        int p = 0;
        int cnt = 0;
        for (int k = 0; k < 9; k++) {
          int y_ = i + pos[k][0];
          int x_ = j + pos[k][1];
          if (y_ < 0 || y_ >= img.size() || x_ < 0 || x_ >= img[0].size())
            continue;
          p += img[y_][x_];
          cnt++;
        }
        ans[i][j] = floor(p / (double)cnt);
      }
    }
    return ans;
  }
};
