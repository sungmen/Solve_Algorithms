function solution(n) {
    var answer = 0;
    for (let i = n; i >= 0; i--) {
        let sum = 0;
        for (let j = i; j >= 0; j--) {
            sum += j;
            if(sum === n)
                answer++;
            else if(sum > n)
                break;
        }
    }
    return answer;
}