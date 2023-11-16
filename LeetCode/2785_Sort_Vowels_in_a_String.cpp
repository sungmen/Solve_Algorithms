class Solution {
public:
  string sortVowels(string s) {
    vector<char> t = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    vector<int> v, cnt;
    for (int i = 0; i < s.size(); i++) {
      if (find(t.begin(), t.end(), s[i]) != t.end()) {
        v.push_back((int)s[i]);
        cnt.push_back(i);
      }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      int ch = v[i];
      int idx = cnt[i];
      s[idx] = ch;
    }
    return s;
  }
};
