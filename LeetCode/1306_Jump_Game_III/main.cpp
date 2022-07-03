class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> chk(n, 0);
        chk[start] = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (!arr[cur]) return 1;
            int pos[2] = {cur - arr[cur], cur + arr[cur]};
            for (int i = 0; i < 2; ++i) {
                if (pos[i] >= 0 && pos[i] < n && !chk[pos[i]]) {
                    chk[pos[i]] = 1;
                    q.push(pos[i]);
                }
            }
        }        
        return 0;
    }
};