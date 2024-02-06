class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int t = searchWord.size();
    int b = 1;
    if (sentence.size() < t)
      return -1;
    if (sentence.substr(0, t) == searchWord)
      return 1;
    for (int i = 0; i < sentence.size(); i++) {
      if (sentence[i] != ' ')
        continue;
      if (i + 1 + t > sentence.size())
        return -1;
      b++;
      string tmp = sentence.substr(i + 1, t);
      if (0 == tmp.compare(searchWord))
        return b;
    }
    return -1;
  }
};
