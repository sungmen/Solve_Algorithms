function solution(citations) {
    var answer = 0;
    citations.sort((a,b)=>a-b);
    let n = citations.length;
    for(let i = n; i >= parseInt(n/2); i--) {
        let res = citations.filter(v => v >= i);
        if (res.length >= i && n - res.length <= i)
            return i;
    }
    return citations[n-1];
}