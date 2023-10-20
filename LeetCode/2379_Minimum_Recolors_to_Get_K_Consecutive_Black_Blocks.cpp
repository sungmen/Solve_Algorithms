class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int answer = 0;
    for (int i = 0; i < k; i++) {
      if (blocks[i] == 'W')
        answer++;
    }
    int tmp = answer;
    for (int i = k; i < blocks.size(); i++) {
      if (blocks[i - k] == 'W')
        tmp--;
      if (blocks[i] == 'W')
        tmp++;
      answer = min(answer, tmp);
    }
    return answer;
  }
};
