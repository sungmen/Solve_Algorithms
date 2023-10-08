class Solution {
public:
  vector<bool> camelMatch(vector<string> &queries, string pattern) {
    vector<string> v;
    string str = "";
    for (auto patt : pattern) {
      if (patt >= 'A' && patt <= 'Z') {
        if (str != "")
          v.push_back(str);
        str = "";
      }
      str += patt;
    }
    if (str != "")
      v.push_back(str);
    int t = 0;
    vector<bool> result;
    for (auto q : queries) {
      vector<string> vstr;
      string stri = "";
      for (auto s : q) {
        if (s >= 'A' && s <= 'Z') {
          if (stri != "")
            vstr.push_back(stri);
          stri = "";
        }
        stri += s;
        if (!(pattern[0] >= 'a' && pattern[0] <= 'z') && stri[0] >= 'a' &&
            stri[0] <= 'z') {
          stri = "";
        }
      }
      if (stri != "")
        vstr.push_back(stri);
      if (vstr.size() != v.size()) {
        result.push_back(false);
        continue;
      }
      bool chk = true;
      for (int i = 0; i < vstr.size(); i++) {
        string pat = v[i];
        string sv = vstr[i];
        if (pat.size() > sv.size()) {
          chk = false;
          break;
        }
        int p = 0;
        for (int j = 0; j < sv.size(); j++) {
          if (pat[p] == sv[j]) {
            p++;
            if (p == pat.size())
              break;
          }
        }
        chk = (p == pat.size());
        if (!chk)
          break;
      }
      result.push_back(chk);
    }
    return result;
  }
};
