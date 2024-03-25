class Solution {
public:
  vector<vector<string>> displayTable(vector<vector<string>> &orders) {
    vector<vector<string>> ans;
    set<string> food;
    map<int, unordered_map<string, int>> table;
    for (auto o : orders) {
      food.insert(o[2]);
      table[stoi(o[1])][o[2]]++;
    }
    vector<string> f;
    f.push_back("Table");
    for (auto it = food.begin(); it != food.end(); it++) {
      f.push_back(*it);
    }
    ans.push_back(f);
    for (auto it = table.begin(); it != table.end(); it++) {
      vector<string> inputD;
      inputD.push_back(to_string(it->first));
      unordered_map<string, int> subUm = it->second;
      for (auto fIdx = food.begin(); fIdx != food.end(); fIdx++) {
        if (subUm.find(*fIdx) == subUm.end()) {
          inputD.push_back("0");
        } else {
          inputD.push_back(to_string(subUm[*fIdx]));
        }
      }
      ans.push_back(inputD);
    }

    return ans;
  }
};
