class Solution {
private:
    int ans = 0, n = 0;
    int alp[26];
    map<int, int> m;
    priority_queue<int> pq;
    
public:
    int minDeletions(string s) {
        for (auto c : s) {
            alp[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (alp[i]) {
                if (!m[alp[i]]) m[alp[i]] = 1;
                else pq.push(alp[i]);
            }
        }
        if (!pq.empty()) {
            n = pq.top();
            n--;
        }
        while(!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            if (n >= cur) n = cur - 1;
            while (n > 0 && m[n]) {n--;}
            ans += cur - n;
            if (n) n--;
        }
        return ans;
    }
};