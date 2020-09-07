#include <stdio.h>
int dp[1001];
int main(){
    int t[5] = {1,4,9,121,484};
    int j = 0;
    for (int i = 1; i < 1001; i++) {
        if(t[j] == i) {
            dp[i]=dp[i-1] + 1;
            if (j < 5) {
                j+=1;
            }
        }
        else {
            dp[i] = dp[i-1];
        }
    }
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("#%d %d\n",i,dp[b]-dp[a-1]);
    }
}