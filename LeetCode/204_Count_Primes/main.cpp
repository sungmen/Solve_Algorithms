class Solution {
public:    
    int countPrimes(int n) {
        if(n < 3) return 0;
        bool chk[5000001];
        for (int i = 2; i <= n; i++) chk[i] = true;
        chk[1] = false;
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (chk[i]) {
                for (int j = i + i; j < n; j += i) {
                    if (chk[j]) {
                        chk[j] = false;
                        cnt++;
                    }
                }
            }
        }
        return n-2-cnt;
    }
};