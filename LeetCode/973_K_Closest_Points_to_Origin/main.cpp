class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<double> pq;
        map<double, vector<vector<int>>> m;
        for (auto point : points) {
            double d = sqrt(point[0] * point[0] + point[1] * point[1]);
            pq.push(-d);
            m[-d].push_back({point[0], point[1]});
        }
        vector<vector<int>> answer;
        while (!pq.empty() && k) {
            double cur = pq.top();
            vector<vector<int>> curv = m[cur];
            pq.pop();
            for (int i = 0; i < curv.size() && k; k--, i++) {
                answer.push_back(curv[i]);
            }
        }
        return answer;
    }
};