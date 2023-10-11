class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
    struct th {
      int val = -1, left = -1, right = 1e6;
    };
    int t = 0;
    int p = 0;
    vector<th> v(s.size() + 1);
    int back = -1;
    for (int i = 0; i < s.size(); i++) {
      int c = s[i];
      if (c == '|') {
        back = i;
        p += t;
        t = 0;
        v[i].val = p;
        v[i].left = back;
        v[i].right = back;
        int tmp = i - 1;
        while (tmp >= 0 && s[tmp] != '|') {
          v[tmp].right = back;
          tmp--;
        }
      } else {
        v[i].val = p;
        v[i].left = back;
        if (back == -1)
          continue;
        t++;
      }
    }

    vector<int> answer;

    for (auto q : queries) {
      int l = v[q[0]].right, r = v[q[1]].left;
      answer.push_back((l >= r ? 0 : v[r].val - v[l].val));
    }
    return answer;
  }
};
