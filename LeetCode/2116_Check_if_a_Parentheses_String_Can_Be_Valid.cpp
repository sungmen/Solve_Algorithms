class Solution {
public:
  bool canBeValid(string s, string locked) {
    bool ans = false;
    if (1 == s.size() % 2)
      return ans;
    vector<int> open;
    vector<int> backup;
    for (int i = 0; i < s.size(); i++) {
      if ('(' == s[i]) {
        if (false == open.empty() && '0' == locked[i]) {
          backup.push_back(i);
          backup.push_back(open.back());
          open.pop_back();
        } else {
          open.push_back(i);
        }
      } else {
        if (true == open.empty()) {
          if ('1' == locked[i]) {
            if (backup.size() < 2) {
              return ans;
            }
            backup.pop_back();
            open.push_back(backup.back());
            backup.pop_back();
          } else {
            open.push_back(i);
          }
        } else {
          if ('0' == locked[i]) {
            backup.push_back(i);
            backup.push_back(open.back());
          }
          open.pop_back();
        }
      }
    }
    if (false == open.empty()) {
      return ans;
    }
    ans ^= 1;
    return ans;
  }
};
