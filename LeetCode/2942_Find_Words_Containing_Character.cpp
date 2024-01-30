class Solution {
public:
  vector<int> findWordsContaining(vector<string> &words, char x) {
    vector<int> answer;
    for (int i = 0; i < words.size(); i++) {
      string word = words[i];
      for (auto w : word) {
        if (w != x)
          continue;
        answer.push_back(i);
        break;
      }
    }
    return answer;
  }
};
