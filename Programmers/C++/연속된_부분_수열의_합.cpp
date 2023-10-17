#include <unordered_map>
#include <vector>
using namespace std;
vector<int> solution(vector<int> sequence, int k) {
  vector<int> answer;
  unordered_map<int, int> um;
  int t = 0;
  um[t] = -1;
  int resSize = 1e9 + 1;
  for (int i = 0; i < sequence.size(); i++) {
    t += sequence[i];
    if (um.find(t - k) != um.end() && resSize > i - um[t - k]) {
      answer = {um[t - k] + 1, i};
      resSize = i - um[t - k];
    }
    um[t] = i;
  }

  return answer;
}
