class Solution {
public:
  pair<int, int> move(char ch) {
    switch (ch) {
    case 'N':
      return {-1, 0};
    case 'E':
      return {0, 1};
    case 'S':
      return {1, 0};
    case 'W':
      return {0, -1};
    }
    return {0, 0};
  }

  bool isPathCrossing(string path) {
    pair<int, int> cur = {0, 0};
    map<pair<int, int>, int> m;
    m[{0, 0}] = 1;
    for (auto ch : path) {
      pair<int, int> next = move(ch);
      cur.first += next.first;
      cur.second += next.second;
      if (m.find(cur) != m.end())
        return true;
      m[cur] = 1;
    }
    return false;
  }
};
