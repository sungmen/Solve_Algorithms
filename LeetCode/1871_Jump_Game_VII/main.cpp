class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back()=='1') return false;
        int n = s.size(), next_cur = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == n - 1) return 1;
            for (int i = max(next_cur, cur + minJump); i <= min(cur + maxJump, n - 1); ++i) {
                if (s[i] == '0') {
                    q.push(i);
                }
            }
            next_cur = min(cur + 1 + maxJump, n);
        }
        return 0;
    }
};