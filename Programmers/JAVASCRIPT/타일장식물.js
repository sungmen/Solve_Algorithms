function solution(N) {
    var answer = 4;
    let arr = [0 ,1, 1, 2, 3, 5, 8,];
    for (let i = 7; i <= 81; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    if (N == 1)
        return answer;
    else 
        for (let i = 2; i <= N; i++) {
            answer += arr[i] * 2;
        }
    return answer;
}