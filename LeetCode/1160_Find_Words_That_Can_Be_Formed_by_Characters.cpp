class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    vector<int> cha(26, 0);
    for (auto it : chars)
      cha[it - 'a']++;
    int answer = 0;
    for (auto word : words) {
      unordered_map<int, int> um;
      for (auto it : word) {
        um[it - 'a']++;
      }
      bool chk = true;
      for (auto it = um.begin(); it != um.end(); it++) {
        if (cha[it->first] < it->second) {
          chk = false;
          break;
        }
      }
      if (chk)
        answer += word.size();
    }
    return answer;
  }
};
