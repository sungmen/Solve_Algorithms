function solution(left, right) {
    var answer = 0;
    for (let i = left; i <= right; i++) {
        answer += (Number.isInteger(Math.sqrt(i))?-i:i);
    }
    return answer;
}