const solution = (n, results) => {
    var answer = 0;
    let d = new Array(n);
    let INF = 1e9;
    for (let i = 0; i < n; i++) d[i] = new Array(n);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            d[i][j] = false;
        }
    }
    for (let i = 0; i < results.length; i++) {
        d[results[i][0]-1][results[i][1]-1] = true;
    }
    for (let i = 0; i < n; i++) for (let j = 0; j < n; j++) for (let k = 0; k < n; k++) if (d[j][i] && d[i][k]) d[j][k] = true;
    for (let i = 0; i < n; i++) {
        let cnt = 0;
        for (let j = 0; j < n; j++) {
            if (d[i][j] || d[j][i]) cnt++;
        }
        if (cnt == n-1) answer++;
    }
    return answer;
}