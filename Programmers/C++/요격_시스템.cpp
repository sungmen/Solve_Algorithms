#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> targets) {
  int answer = 0;
  sort(targets.begin(), targets.end());
  int end = 0;
  for (vector<int> cur : targets) {
    int s = cur[0];
    int e = cur[1];
    if (end <= s) {
      end = e;
      ++answer;
      continue;
    }
    end = min(end, e);
  }
  return answer;
}
