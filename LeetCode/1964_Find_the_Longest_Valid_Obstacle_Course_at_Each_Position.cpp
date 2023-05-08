class Solution {
public:
    const int MAX = 1e7;
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        int n = obstacles.size();
        vector<int> vec(n + 1, MAX + 1);
        vec[0] = -MAX;
        for (int i = 0; i < n; i++)
        {
          auto it = upper_bound(vec.begin(), vec.end(), obstacles[i]) - vec.begin();
          vec[it] = obstacles[i];
          ans.push_back(it);
        }
        return ans;
    }
};