class Solution {
public:
  struct th {
    string str;
    int cnt;
  };
  int openLock(vector<string> &deadends, string target) {
    set<string> s;
    for (auto t : deadends) {
      if ("0000" == t) {
        return -1;
      }
      s.insert(t);
    }
    queue<th> q;
    q.push({"0000", 0});
    s.insert("0000");
    while (!q.empty()) {
      th cur = q.front();
      q.pop();
      if (target == cur.str) {
        return cur.cnt;
      }
      for (int i = 0; i < 4; i++) {
        string str1 = cur.str;
        str1[i]++;
        if (str1[i] > '9') {
          str1[i] -= 10;
        }
        if (s.find(str1) == s.end()) {
          s.insert(str1);
          q.push({str1, cur.cnt + 1});
        }
        string str2 = cur.str;
        str2[i]--;
        if (str2[i] < '0') {
          str2[i] += 10;
        }
        if (s.find(str2) == s.end()) {
          s.insert(str2);
          q.push({str2, cur.cnt + 1});
        }
      }
    }
    return -1;
  }
};
