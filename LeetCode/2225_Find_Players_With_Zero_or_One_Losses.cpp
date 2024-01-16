class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    map<int, int> win;
    map<int, int> lose;
    for (auto match : matches) {
      win[match[0]]++;
      lose[match[1]]++;
    }
    vector<int> w, l;
    for (auto it = win.begin(); it != win.end(); it++) {
      if (lose.find(it->first) == lose.end()) {
        w.push_back(it->first);
      }
    }
    for (auto it = lose.begin(); it != lose.end(); it++) {
      if (it->second == 1)
        l.push_back(it->first);
    }
    return {w, l};
  }
};
