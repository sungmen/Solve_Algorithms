class Solution {
public:
  int vowel(char ch) {
    switch (ch) {
    case 'a': {
      return 0;
    }
    case 'e': {
      return 1;
    }
    case 'i': {
      return 2;
    }
    case 'o': {
      return 3;
    }
    case 'u': {
      return 4;
    }
    }
    return -2;
  }
  int longestBeautifulSubstring(string word) {
    vector<pair<int, int>> v;
    char ch = '-';
    int cnt = 0;
    for (auto it : word) {
      if (ch != it) {
        v.push_back({vowel(ch), cnt});
        ch = it;
        cnt = 1;
      } else {
        cnt++;
      }
    }
    v.push_back({vowel(ch), cnt});
    int ans = 0;
    int c = 0;
    int sum = 0;
    for (int i = 1; i < v.size(); i++) {
      if (v[i - 1].first == c && v[i - 1].first - v[i].first == -1) {
        c++;
        sum += v[i - 1].second;
        if (v[i].first == 4) {
          ans = max(ans, sum + v[i].second);
          c = 0;
          sum = 0;
        }
      } else {
        c = 0;
        sum = 0;
      }
    }
    return ans;
  }
};
