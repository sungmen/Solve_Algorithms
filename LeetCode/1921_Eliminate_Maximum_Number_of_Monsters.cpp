class Solution {
public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    vector<int> m;
    for (int i = 0; i < dist.size(); i++)
      m.push_back(ceil((double)dist[i] / (double)speed[i]));
    sort(m.begin(), m.end());
    for (int i = 0; i < speed.size(); i++) {
      if (m[i] <= i)
        return i;
    }
    return dist.size();
  }
};
