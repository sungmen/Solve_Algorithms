class Solution {
public:
  struct th {
    int y;
    int x;
    int p;
  };
  int POS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool isRobotBounded(string instructions) {
    th cur = {0, 0, 0};
    for (auto it : instructions) {
      if ('G' == it) {
        cur.y += POS[cur.p][0];
        cur.x += POS[cur.p][1];
      } else if ('L' == it) {
        cur.p--;
        if (cur.p < 0)
          cur.p = 3;
      } else {
        cur.p++;
        if (cur.p > 3)
          cur.p = 0;
      }
    }
    if (0 == cur.y && 0 == cur.x)
      return true;
    return 0 != cur.p;
  }
};
