class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) return 0;
        queue<pair<int,int>> q;
        q.push ({amount, 0});
        vector<bool> chk(10001, false);
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            if (cur.first == 0) {
                return cur.second;
            }
            q.pop();
            for (int i = coins.size()-1; i >= 0; i--) {
                if (cur.first-coins[i] < 0 || chk[cur.first-coins[i]]) continue;
                q.push({cur.first-coins[i], cur.second+1});
                chk[cur.first-coins[i]] = true;
            }
        }
        return -1;
    }
};