function solution(a, b) {
    let month=[31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let week = [ "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"];
    let answer = [];
    for(let i = 0; i < 12; i++)
        answer.push([]);
    let num = 0;
    for(let i = 0; i < 12; i++) {
        for (let j = 0; j < month[i]; j++) {
            answer[i][j] = week[num % 7];
            num+=1;
        }
    }
    
    return answer[a - 1][b - 1];
}
