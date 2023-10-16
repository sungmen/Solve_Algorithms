#include <algorithm>
#include <vector>
using namespace std;
int solution(vector<int> picks, vector<string> minerals) {
  int answer = 0;
  vector<pair<int, vector<int>>> v;
  int sum = 0;
  for (auto i : picks)
    sum += i;
  int f = 0, s = 0, t = 0;
  for (int i = 0; i < minerals.size() && i < sum * 5; i++) {
    string str = minerals[i];
    f += 1;
    s += 1;
    t += 1;
    if ("diamond" == str) {
      s += 4;
      t += 24;
    } else if ("iron" == str) {
      t += 4;
    }
    if (i % 5 == 4) {
      v.push_back({-t, {f, s, t}});
      f = 0;
      s = 0;
      t = 0;
    }
  }
  if (t != 0)
    v.push_back({-t, {f, s, t}});
  sort(v.begin(), v.end());
  for (auto i : v) {
    if (picks[0]) {
      answer += i.second[0];
      picks[0]--;
    } else if (picks[1]) {
      answer += i.second[1];
      picks[1]--;
    } else if (picks[2]) {
      answer += i.second[2];
      picks[2]--;
    }
  }
  return answer;
}
