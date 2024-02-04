class Solution {
public:
  string minWindow(string s, string t) {
    string ans = "";
    map<char, int> cntM;
    for (auto i : t) {
      cntM[i]++;
    }
    int i = 0;
    for (; i < s.size(); i++) {
      if (cntM.find(s[i]) != cntM.end()) {
        break;
      }
    }
    map<char, int> charM;
    int checkM = cntM.size();
    int checkT = 0;
    int start = i;
    for (; i < s.size(); i++) {
      if (cntM.find(s[i]) == cntM.end()) {
        continue;
      }
      int cntNum = cntM[s[i]];
      charM[s[i]]++;
      if (charM[s[i]] < cntM[s[i]]) {
        continue;
      }
      if (charM[s[i]] > cntM[s[i]] && s[start] == s[i]) {
        start++;
        charM[s[i]]--;
        continue;
      }
      if (charM[s[i]] == cntM[s[i]]) {
        checkT++;
      }
      if (checkT != checkM) {
        continue;
      }
      string strTmp = s.substr(start, i - start + 1);
      if (ans == "" || ans.size() > strTmp.size()) {
        ans = strTmp;
      }
      while (start < i) {
        if (cntM.find(s[start]) == cntM.end()) {
          ++start;
          string strTmp = s.substr(start, i - start + 1);
          if (ans == "" || ans.size() > strTmp.size()) {
            ans = strTmp;
          }
          continue;
        }
        --charM[s[start]];
        if (0 == charM[s[start]]) {
          charM.erase(s[start]);
          --checkT;
          ++start;
          break;
        }
        if (charM[s[start]] >= cntM[s[start]]) {
          ++start;
          string strTmp = s.substr(start, i - start + 1);
          if (ans == "" || ans.size() > strTmp.size()) {
            ans = strTmp;
          }
          continue;
        }
        --checkT;
        ++start;
        break;
      }
      while (start < i) {
        if (cntM.find(s[start]) != cntM.end())
          break;
        start++;
      }
    }
    return ans;
  }
};
