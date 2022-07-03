class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int answer = 2e9;
        int arr[2] = {0, 0};
        set<int> s;
        for (auto p : position) {
            s.insert(p);
            if (p % 2) {
                arr[1]++;
            } else {
                arr[0] ++;
            }
        }
        for (auto it = s.begin(); it != s.end(); ++it) {
            answer = min(answer, arr[!(*it % 2)]);
        }
        return answer;
    }
};