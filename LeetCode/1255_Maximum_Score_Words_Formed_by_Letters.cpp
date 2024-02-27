class Solution {
public:
  int answer = 0;
  void dfs(int ans, int idx, map<char, int> cur, map<char, int> &m,
           vector<map<char, int>> &vmword, vector<int> &vscore) {
    map<char, int> curvmword = vmword[idx];
    bool chk = true;
    for (auto it = curvmword.begin(); it != curvmword.end(); it++) {
      cur[it->first] += it->second;
      if (m[it->first] < cur[it->first]) {
        chk = false;
        break;
      }
    }
    if (false == chk) {
      return;
    }
    ans += vscore[idx];
    if (answer < ans) {
      answer = ans;
    }
    for (int i = idx + 1; i < vscore.size(); i++) {
      dfs(ans, i, cur, m, vmword, vscore);
    }
  }
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    map<char, int> m;
    for (auto letter : letters) {
      m[letter]++;
    }
    vector<map<char, int>> vmword;
    vector<int> vscore;
    for (auto word : words) {
      map<char, int> curm;
      int n = 0;
      for (auto it : word) {
        curm[it]++;
        n += score[it - 'a'];
      }
      vscore.push_back(n);
      vmword.push_back(curm);
    }
    for (int i = 0; i < words.size(); i++) {
      map<char, int> cur;
      dfs(0, i, cur, m, vmword, vscore);
    }
    return answer;
  }
};
