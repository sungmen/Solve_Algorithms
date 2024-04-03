class Solution {
public:
  string lastNonEmptyString(string s) {
    int arr[26][2];
    for (int i = 0; i < 26; i++) {
      memset(arr, 0, sizeof(arr[i]));
    }
    for (int i = 0; i < s.size(); i++) {
      arr[s[i] - 'a'][0] = i;
      arr[s[i] - 'a'][1]++;
    }
    int maxLen = 0;
    vector<int> lastIndex;
    string result = "";
    for (int i = 0; i < 26; i++) {
      if (0 == arr[i][1]) {
        continue;
      }
      if (maxLen < arr[i][1]) {
        maxLen = arr[i][1];
        lastIndex.clear();
        lastIndex.push_back(arr[i][0]);
      } else if (maxLen == arr[i][1]) {
        lastIndex.push_back(arr[i][0]);
      }
    }
    sort(lastIndex.begin(), lastIndex.end());
    for (auto it : lastIndex) {
      result += s[it];
    }
    return result;
  }
};
