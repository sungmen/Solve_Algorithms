let solution = (n, computers) => {
    let chk = new Array(n); chk.fill(false);
    var answer = 0;
    for (let i = 0; i < n; i++) {
        if (chk[i] == false) {
            ++answer;
            let stk = [];
            stk.push(i);
            chk[i] = true;
            while (stk.length != 0) {
                let t = stk.shift();
                for(let j = 0; j < n; j++) {
                    if (computers[t][j] == 1 && chk[j] == false) {
                        chk[j] = true;
                        stk.push(j);
                    }
                }
            }
        }
    }
    return answer;
}