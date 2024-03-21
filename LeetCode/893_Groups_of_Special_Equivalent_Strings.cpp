class Solution {
public:
  int numSpecialEquivGroups(vector<string> &words) {
    set<string> setStr;
    for (auto word : words) {
      string odd = "", even = "";
      for (int i = 0; i < word.size(); i++) {
        if (i % 2) {
          even.push_back(word[i]);
        } else {
          odd.push_back(word[i]);
        }
      }
      sort(even.begin(), even.end());
      sort(odd.begin(), odd.end());
      setStr.insert(odd + even);
    }
    return setStr.size();
  }
};
