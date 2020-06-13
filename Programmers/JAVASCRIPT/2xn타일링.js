let dp = [60000];

let init = () => {
    for (let i = 5; i <= 60000; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    }
}
let solution = (n) => {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    init();
    return dp[n];
}