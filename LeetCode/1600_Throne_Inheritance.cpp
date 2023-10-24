class ThroneInheritance {
public:
  unordered_map<string, vector<string>> um;
  string c = "";
  unordered_map<string, int> umd;

  ThroneInheritance(string kingName) { c = kingName; }

  void birth(string parentName, string childName) {
    um[parentName].push_back(childName);
  }

  void death(string name) { umd[name] = 1; }

  void dfs(vector<string> &res, string str) {
    if (umd.find(str) == umd.end()) {
      res.push_back(str);
    }
    if (um.find(str) == um.end())
      return;
    for (auto it : um[str]) {
      dfs(res, it);
    }
  }

  vector<string> getInheritanceOrder() {
    vector<string> res;
    dfs(res, c);
    return res;
  }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
