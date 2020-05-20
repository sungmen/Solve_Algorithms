function solution(budgets, M) {
    var answer = 0;
    let sum2 = budgets.reduce((a,b)=>a+b);
    budgets.sort(function(a,b){return b-a});
    if (M >= sum2)
        return budgets[0];
    let n = budgets[0], min = 0, mid = 0, com = 0;
    while(true){
        mid = parseInt((n + min)/2);
        let sum = 0;
        for(let i = 0; i < budgets.length; i++) {
            sum += (budgets[i] >= mid ? mid : budgets[i]);
        }
        if (mid == com) {
            return mid;
        }
        sum > M ? n = mid : min = mid;
        com = mid;
    }
    console.log(answer);
    return n;
}