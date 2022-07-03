/**
* Runtime: 36 ms, faster than 31.82% of C++ online submissions for Combination Sum.
* Memory Usage: 16.1 MB, less than 38.73% of C++ online submissions for Combination Sum.
*/

class Solution {
public:
    struct th {
        vector<int> v;
        int base;
        int sum;
    };
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return {{}};
        vector<vector<int>> res;
        queue<th> q;
        for (int i = 0; i < candidates.size(); i++) {
            q.push({{candidates[i]}, candidates[i], candidates[i]});
        }
        while(!q.empty()) {
            th cur = q.front();
            q.pop();
            if (cur.sum == target) {
                res.push_back(cur.v);
                continue;
            }
            for (int i = 0; i < candidates.size(); i++) {
                if(cur.base > candidates[i] || target - cur.sum < candidates[i]) continue;
                vector<int> cur_v = cur.v;
                cur_v.push_back(candidates[i]);
                q.push({cur_v, candidates[i], cur.sum + candidates[i]});
            }
        }        
        return res;
    }
};