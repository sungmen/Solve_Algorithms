class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    unordered_set<string> us;
    us.insert(s);
    string minVal = s;
    queue<string> q;
    q.push(s);
    string ans = s;
    int n = s.size();
    while (false == q.empty()) {
      string cur = q.front();
      q.pop();
      if (minVal > cur) {
        minVal = cur;
        ans = cur;
      }
      string t1 = cur;
      for (int i = 1; i < n; i += 2) {
        if ((t1[i] + a) > '9') {
          t1[i] = t1[i] + a - 10;
        } else {
          t1[i] = t1[i] + a;
        }
      }
      if (us.find(t1) == us.end()) {
        us.insert(t1);
        q.push(t1);
      }
      int c = b % n;
      string t2 = cur.substr(c) + cur.substr(0, c);
      if (us.find(t2) == us.end()) {
        us.insert(t2);
        q.push(t2);
      }
    }
    return ans;
  }
};
