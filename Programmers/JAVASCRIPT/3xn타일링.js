let dp = [5001];

let init = () => {
    for (let i = 1; i <= 5000; i++) {
        dp[i] = dp[i-1] * 3;
        for (let k = i - 2; k >= 0; k--) {
            dp[i] += dp[k] * 2;
        }
        dp[i] = dp[i] % 1000000007;
    }
}

let solution = (n) => {
    dp[0] = 1;
    init();
    if(n&1) {
        return 0;
    } else {
        return dp[n/2];
    }
}